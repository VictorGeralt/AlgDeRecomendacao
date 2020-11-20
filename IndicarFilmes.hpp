#include "Comparador.hpp"
#include <iostream>

struct Filmes
{
    float notaTotal;
    int id;
    Filmes(float notaTotal,int id):notaTotal(notaTotal),id(id){};
    Filmes()=default;
};

Lista <Filmes> AnalizarFilmes(Lista<Pontuacao> semelhantes,Lista<netflix> &usuario){
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
    auto aux= Recomendacoes.getPrimeiro();
    do
    {
        if (aux->valores.id==aux->proximo->valores.id)
        {
            aux->valores.notaTotal+=aux->proximo->valores.notaTotal;
            Recomendacoes.TirarOProximo(aux);
        }else{
            aux=aux->proximo;
        }
    } while (aux->proximo!=nullptr);
    


    for (auto i=Recomendacoes.getPrimeiro();i !=Recomendacoes.getUltimo()->anterior;i=i->proximo){
       
    auto jMax = i;   
    for (auto j = i->proximo; j != Recomendacoes.getUltimo()->proximo; j=j->proximo){
          
        if (j->valores.notaTotal > jMax->valores.notaTotal)
        {
            jMax = j;
        }
    }
    if (jMax != i) 
    {
        auto aux=i->valores;
        i->valores=jMax->valores;
        jMax->valores=aux;
        
    }
}

    for (auto i = usuario.getPrimeiro(); i!=nullptr ; i=i->proximo){

        int aux=std::stoi(i->valores.idFilme);

        for (auto j=Recomendacoes.getPrimeiro();j !=nullptr;j=j->proximo)
        {
            if (aux==j->valores.id)
            {
                Recomendacoes.Tirar(j);
            }
            
        }  
    }

    return std::move(Recomendacoes);
}


void KMelhoresFilmes(Lista<Filmes> filmes,int k){
        auto aux=filmes.getPrimeiro();
        for (size_t i=0; i<k; i++)
        {
        if (aux->valores.id>493||aux->valores.id<0)
        {
        aux=aux->proximo;
        i--;
        }else{
        std::cout<<aux->valores.id<<"-";
        std::cout<<aux->valores.notaTotal<<"\n";
        aux=aux->proximo;
        }
        }
}