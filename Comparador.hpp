#include "LerUsuario.hpp"
#include <cmath>
#include <iostream>


struct Pontuacao
{
    Lista<usuario> u;
    float distanciaEuclidiana;
    int filmesEmComum;
    Pontuacao(Lista<usuario> u,float distanciaEuclidiana,int filmesEmComum): u(u),distanciaEuclidiana(distanciaEuclidiana),filmesEmComum(filmesEmComum){};
    Pontuacao()=default;
};


Pontuacao calcularDistancia(Lista <usuario> &user,Lista<usuario> comparado){
    float distanciaEuclidiana=0;
    int filmesEmComum=0;
    for (auto i = user.getPrimeiro(); i!=user.getUltimo() ; i=i->proximo){
        auto aux=i->valores;
        for (auto j=comparado.getPrimeiro() ; j != comparado.getUltimo() ; j=j->proximo){
            if (std::stoi(aux.idFilme)==std::stoi(j->valores.idFilme)){
                distanciaEuclidiana+=pow((std::stoi(aux.Nota)-std::stoi(j->valores.Nota)),2);
                filmesEmComum++;
            }   
        }
    }
    distanciaEuclidiana=sqrt(distanciaEuclidiana);

    
    return std::move(Pontuacao(user,distanciaEuclidiana,filmesEmComum));
}

float pontos(Pontuacao &p){
    return (p.filmesEmComum*(1+( 1 *p.distanciaEuclidiana)));
}

Lista <Pontuacao> KMaisParecidos(Lista<Pontuacao> &P,int K){
    Lista <Pontuacao> aux;
    float min = pontos(P.getPrimeiro()->valores);
    auto Ponta = P.getPrimeiro();
    auto menor= P.getPrimeiro();
        for (size_t i = 0; i < K; i++){
            aux.colocarNoUltimo(Ponta->valores);
            if (Ponta->valores.distanciaEuclidiana<min){
                min=pontos(Ponta->valores);
                menor=aux.getUltimo();
            }
            Ponta=Ponta->proximo;
        }
        for (auto i = Ponta; i !=nullptr; i=i->proximo){
            if (pontos(i->valores)>min){
                min= pontos(i->valores);
                menor->valores=i->valores;
                    for (auto j = aux.getPrimeiro(); j!= nullptr; j=j->proximo){
                        if (pontos(j->valores)<min)
                        {
                            min=pontos(j->valores);
                            menor=j;
                        }   
                    }       
            }  
        }

    Lista<Pontuacao> list;
    list.colocarNoUltimo(Pontuacao(Lista<usuario> (), 12,5));

    return std::move(aux);
}


