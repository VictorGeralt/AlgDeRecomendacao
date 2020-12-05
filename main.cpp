
#include "LerLista.hpp"
#include "LerUsuario.hpp"
#include "Sort.hpp"
#include "NovaEntrada.hpp"
#include "netflix.hpp"


using namespace std;
int main(){
    
    Lista<netflix> n(GetLista());
    int k=10;
    int tam=13;
    
    Sort(n);


    Lista<Lista<netflix>>usuarios(CriarUsuarios(n));

   
    Lista<netflix> u(getUsuario());


    Lista<Pontuacao> p;

    
    for (auto i = usuarios.getPrimeiro(); i != usuarios.getUltimo(); i=i->proximo)
    {
    p.colocarNoUltimo(calcularDistancia(i->valores,u));
    
    };


    cout<<" ------------------------------------"<<endl;
    cout<<"|Melhores usuario para o usuario base|"<<endl;
    cout<<" ------------------------------------"<<endl;


    Lista<Pontuacao> kmelhores{KMaisParecidos(p,k)};
    
    for (auto i = kmelhores.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
        cout<<"ID do usuario: "<<i->valores.id<<endl;    
    }


    cout<<" \n\n\n"<<endl;


    cout<<" ------------------------------------"<<endl;
    cout<<"|Melhores filmes para o usuario base | "<<endl;
    cout<<" ------------------------------------"<<endl;

    auto recomendacoes{AnalizarFilmes(kmelhores,u,k)};

    cout<<" \n\n\n"<<endl;

    cout<<" ----------------------------------"<<endl;
    cout<<"|     Colocando dados no Cache     | "<<endl;
    cout<<" ----------------------------------"<<endl;

    Cache cache=criarCache(u,recomendacoes,tam);
    

    Lista<netflix> u2(getNovoUsuario());
    cout<<" \n\n\n"<<endl;


    cout<<" ---------------------------------"<<endl;
    cout<<"|         Testando Cache          |"<<endl;
    cout<<" ---------------------------------"<<endl;

    cout<<"Verificando conteudo de um item do cache:  "<<cache.getItem(4)->filmes.getPrimeiro()->valores.id<<endl;
    cout<<"Inserindo item aleatorio no cache:           ";
    cache.inserirCache(155555555,recomendacoes);
    cout<<"Verificando dados do item aleatorio criado no cache:  "<<cache.getItem(155555555)->filmes.getPrimeiro()->valores.id<<endl;

    cout<<" \n\n\n"<<endl;

    incluirNovoUsuario(usuarios,cache,u2);

    
    
    
    return 0;
}