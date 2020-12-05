
#include "LerLista.hpp"
#include "LerUsuario.hpp"
#include "Sort.hpp"
#include "Cache.hpp"
#include "netflix.hpp"


using namespace std;
int main(){
    
    Lista<netflix> n(GetLista());
    int k=10;
    int tam=5;
    
    Sort(n);

    // ponta<netflix> *verificador1= n.getPrimeiro();

    // while (verificador1!=nullptr)
    // {
    //     cout<<verificador1->valores.idUser<<"-";
    //     cout<<verificador1->valores.idFilme<<"-";
    //     cout<<verificador1->valores.Nota<<"\n";
    //     verificador1=verificador1->proximo;
    // }


    Lista<Lista<netflix>>usuarios(CriarUsuarios(n));

    // cout<<"numero de usuarios : "<<usuarios.getTamanho()<<"\n";
    // auto verificador2= usuarios.getPrimeiro()->valores.getPrimeiro();
    // auto verificador3= usuarios.getPrimeiro();

    // for (auto i = usuarios.getPrimeiro(); i != nullptr; i=i->proximo)
    // {   
    //         cout<<i->valores.getTamanho()<<"\n";
    
    // }

    Lista<netflix> u(getUsuario());

    // ponta<netflix> *verificador4=u.getPrimeiro();

    // for (auto i=u.getPrimeiro(); i!=u.getUltimo()->proximo; i=i->proximo)
    // {
    //     cout<<i->valores.idUser<<"-";
    //     cout<<i->valores.idFilme<<"-";
    //     cout<<i->valores.Nota<<"\n";

    // }

    Lista<Pontuacao> p;

    
    for (auto i = usuarios.getPrimeiro(); i != usuarios.getUltimo(); i=i->proximo)
    {
    p.colocarNoUltimo(calcularDistancia(i->valores,u));
    
    };


    Lista<Pontuacao> kmelhores{KMaisParecidos(p,k)};
    
    for (auto i = kmelhores.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
        cout<<"ID: "<<i->valores.id<<"--"<<"Filmes em Comum: "<<i->valores.filmesEmComum<<"--"<<"Distancia: "<<i->valores.distanciaEuclidiana<<"--"<<"Pontuacao: "<<pontos(i->valores)<<"\n";    
    }
    
    Lista<Filmes> recomendacoes{AnalizarFilmes(kmelhores,u)};

    KMelhoresFilmes(recomendacoes,k);


    // Cache cache;
    // cache.criarCache(u,recomendacoes,tam);

    // cache.getItem(1);

    // cache.inserirCache(5,recomendacoes);

    // auto verificador5=cache.getItem(5);
    // cout<<(cache.cache.find(5)==cache.cache.end() ? "sim" :"nao");
    
    return 0;
}