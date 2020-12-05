#include "IndicarFilmes.hpp"
#include <map>

using namespace std;

struct Cache_U
{
    Lista<Filmes> filmes;
    int contador;
    Cache_U ()=default;
    Cache_U (Lista<Filmes> filmes):filmes(filmes),contador(1){}
};


class Cache
{
    private:
    unsigned short tamanho{20};

    public:

    Cache()=default;
    Cache(unsigned short TAM):tamanho(TAM){}

    map<int,Cache_U> cache;

    Cache criarCache(Lista<netflix> usuario,Lista<Filmes> filmes,int tamanho);
    void inserirCache(int chave,Lista<Filmes> filmes);
    Lista<Filmes> &getItem(int chave);
    void LRU();
    

};



Cache Cache::criarCache(Lista<netflix> usuario,Lista<Filmes> filmes,int tamanho){
    Cache cache(tamanho);
    
    for (auto i = usuario.getPrimeiro(); i !=nullptr; i=i->proximo)
    {
        if (stoi(i->valores.idFilme)<493&&stoi(i->valores.idFilme)>0)
        {
        cache.inserirCache(stoi(i->valores.idFilme),filmes);
    } 
}
return cache;}


void Cache::inserirCache(int chave,Lista<Filmes> filmes){
    Cache_U item{filmes};
    if(cache.size()>=tamanho){
        this->LRU();
    }
    cache.insert({chave,filmes});
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
        i.second.contador=0;
}
 cout<<"Chave deletada: "<<cache.find(chave)->first<<"\n";
 cache.erase(cache.find(chave));   
}


Lista<Filmes> &Cache::getItem(int chave){
    auto listaFilmes{&cache.find(chave)->second};
    listaFilmes->contador++;
    return listaFilmes->filmes;
}