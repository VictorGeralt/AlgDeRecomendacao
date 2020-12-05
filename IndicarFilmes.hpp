#include "Comparador.hpp"
#include <iostream>
#include <map>


struct Filmes
{
    float notaTotal;
    int id;
    Filmes(float notaTotal,int id):notaTotal(notaTotal),id(id){};
    Filmes()=default;
};


Lista<Filmes> AnalizarFilmes(Lista<Pontuacao> semelhantes,Lista<netflix> &usuario,int k){
    Lista <Filmes> Recomendacoes;
    Filmes filme;
    for (auto i = semelhantes.getPrimeiro(); i!=semelhantes.getUltimo() ; i=i->proximo){
        for ( auto j = i->valores.u.getPrimeiro(); j!=i->valores.u.getUltimo() ; j=j->proximo )
        {
            filme.id=std::stoi(j->valores.idFilme);
            filme.notaTotal=std::stoi(j->valores.Nota);
            Recomendacoes.colocarNoUltimo(filme);
        }
    }


     for (auto i=Recomendacoes.getPrimeiro();i !=Recomendacoes.getUltimo()->anterior;i=i->proximo){
       
    auto jMin = i;   
    for (auto j = i->proximo; j != Recomendacoes.getUltimo()->proximo; j=j->proximo){
          
        if (j->valores.id < jMin->valores.id)
        {
            jMin = j;
        }
    }
    if (jMin != i) 
    {
        auto aux=i->valores;
        i->valores=jMin->valores;
        jMin->valores=aux;
        
    }
}

    std::map<int,float> novaRecomendacao;
    float maiornota=0;

    auto aux= Recomendacoes.getPrimeiro()->proximo;
    do
    {
        if (aux->valores.id!=aux->proximo->valores.id)
        {
            aux->valores.notaTotal+=aux->anterior->valores.notaTotal;
            novaRecomendacao.insert({aux->valores.id,aux->valores.notaTotal});
            maiornota=maiornota<aux->valores.notaTotal ? aux->valores.notaTotal:maiornota;
            aux->valores.notaTotal=0;
            aux=aux->proximo;

        }else{
            aux->valores.notaTotal+=aux->anterior->valores.notaTotal;
            Recomendacoes.TirarOAnterior(aux);
            aux=aux->proximo;
        }
    } while (aux->proximo!=nullptr);

    for (auto i = usuario.getPrimeiro(); i!=nullptr; i=i->proximo)
    {   
        if (novaRecomendacao.find(std::stoi(i->valores.idFilme))!=novaRecomendacao.end())
        {
            novaRecomendacao.erase(novaRecomendacao.find(std::stoi(i->valores.idFilme)));
        }
        
    }
    

    std::pair<int,float> sort[novaRecomendacao.size()];
    int j=0;
    for (auto &&i : novaRecomendacao)
    {
        sort[j]=i;
        j++;
    }
    
    

    radixsort(sort,novaRecomendacao.size(),maiornota);

    Lista<Filmes> finalList;


    for (auto i = novaRecomendacao.size()-1; i > novaRecomendacao.size()-(k+1); i--)
    {
        finalList.colocarNoUltimo(Filmes(sort[i].second,sort[i].first));
        std::cout<<"ID do filme:   "<<finalList.getUltimo()->valores.id<<"         Nota total do filme: "<<finalList.getUltimo()->valores.notaTotal<<std::endl;
    }

        
    return finalList;
}



