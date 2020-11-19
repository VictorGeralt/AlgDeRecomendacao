#include <iostream>
#include "LerLista.hpp"
#include "LerUsuario.hpp"
#include "Sort.hpp"
#include "IndicarFilmes.hpp"
#include "netflix.hpp"


using namespace std;
int main(){
    
    Lista<netflix> n(GetLista());
    int k;
    
    Sort(n);

    // ponta<netflix> *verificador1= n.getPrimeiro();

    // while (verificador1!=nullptr)
    // {
    //     cout<<verificador1->valores.idUser<<"-";
    //     cout<<verificador1->valores.idFilme<<"-";
    //     cout<<verificador1->valores.Nota<<"\n";
    //     verificador1=verificador1->proximo;
    // }


    Lista<Lista<usuario>>usuarios(CriarUsuarios(n));

    // cout<<"numero de usuarios : "<<usuarios.getTamanho()<<"\n";

    // ponta<usuario> *verificador2=usuarios.getPrimeiro()->valores.getPrimeiro();
    // for (auto i=usuarios.getPrimeiro()->valores.getPrimeiro(); i!=usuarios.getPrimeiro()->valores.getUltimo(); i=i->proximo)
    // {
    //     cout<<verificador2->valores.idFilme<<"-";
    //     cout<<verificador2->valores.Nota<<"\n";
    //     verificador2=verificador2->proximo;

    // }



    Lista<usuario> u(getUsuario());

    // ponta<usuario> *verificador3=u.getPrimeiro();

    // for (auto i=u.getPrimeiro(); i!=u.getUltimo()->proximo; i=i->proximo)
    // {
    //     cout<<i->valores.idFilme<<"-";
    //     cout<<i->valores.Nota<<"\n";

    // }

    Lista<Pontuacao> p;

    cout<<"Digite quantos usuarios voce quer receber:";
    cin>>k;

    for (auto i = usuarios.getPrimeiro(); i != usuarios.getUltimo(); i=i->proximo)
    {
    p.colocarNoUltimo(calcularDistancia(i->valores,u));
    
    };



    
    Lista<Pontuacao> kmelhores{KMaisParecidos(p,k)};
    
    for (auto i = kmelhores.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
        cout<<i->valores.filmesEmComum<<"---"<<i->valores.distanciaEuclidiana<<"---"<<pontos(i->valores)<<"\n";    
    }
    
    Lista<Filmes> recomendacoes{AnalizarFilmes(kmelhores,u)};


    for (auto i=recomendacoes.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
        cout<<i->valores.id<<"-";
        cout<<i->valores.notaTotal<<"\n";

    }

    return 0;
}