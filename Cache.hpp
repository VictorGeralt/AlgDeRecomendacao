#include "IndicarFilmes.hpp"
using namespace std;

struct Cache_U
{
    Lista<Filmes> filmes;
    int contador=0;
    Cache_U ()=default;
    Cache_U (Lista<Filmes> filmes):filmes(filmes),contador(0){}
};


class Cache
{
    private:
    int tamanho{30};

    public:

    Cache()=default;
    Cache(int TAM):tamanho(TAM){}

    map<int,Cache_U> cache;

    void inserirCache(int chave,Lista<Filmes> filmes);
    Cache_U *getItem(int chave);
    void LRU();
    void aumentarContador(int chave);
    int getTam();
    int getMaxTam();

    

};

int Cache::getTam(){
    return cache.size();
}

int Cache::getMaxTam(){
    return tamanho;
}

Cache criarCache(Lista<netflix> usuario,Lista<Filmes> filmes,int tamanho=14){
    Cache cache(tamanho);
     for (auto i = usuario.getPrimeiro(); i !=nullptr; i=i->proximo)
    {
        cache.inserirCache(stoi(i->valores.idFilme),filmes);
    }

return cache;}


void Cache::inserirCache(int chave,Lista<Filmes> filmes){
    Cache_U item{filmes};
    
    if (cache.find(chave)==cache.end()){
        if(cache.size()>=tamanho){
        this->LRU();
    }
    this->cache.insert({chave,filmes});   
    }else 
    {
       cache.at(chave)=filmes;
    }
    
}

void Cache::LRU(){
    int chave{cache.begin()->first};
    int menor{cache.begin()->second.contador};
    for ( auto &&i:cache)
    {
        if(i.second.contador<menor){
            chave=i.first;
            menor=i.second.contador;
        }
        i.second.contador=1;
}
 cout<<"Chave deletada por LRU: "<<cache.find(chave)->first<<"\n";
 cache.erase(cache.find(chave));   
}

void Cache::aumentarContador(int chave){
    cache.find(chave)->second.contador++;
}

Cache_U *Cache::getItem(int chave){
   auto item=cache.find(chave);
   if (item!=cache.end())
   {
       item->second.contador++;
       return &(item->second);
   }else
   {
       return nullptr;
   }
}