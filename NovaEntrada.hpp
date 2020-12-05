#include "Cache.hpp"

 void incluirNovoUsuario(Lista<Lista<netflix>>&usuariosPadrao,Cache cache,Lista<netflix> u){
    int k=10;


    Lista<Pontuacao> p2;
    
    for (auto i = usuariosPadrao.getPrimeiro(); i != usuariosPadrao.getUltimo(); i=i->proximo)
    {
    p2.colocarNoUltimo(calcularDistancia(i->valores,u));
    };
    

    cout<<" ------------------------------------"<<endl;
    cout<<"|Melhores usuario para o novo Usuario|"<<endl;
    cout<<" ------------------------------------"<<endl;

    Lista<Pontuacao> kmelhores{KMaisParecidos(p2,k)};
    
    for (auto i = kmelhores.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
        cout<<"ID do usuario: "<<i->valores.id<<endl;    
    }



        for (auto i = u.getPrimeiro(); i!=nullptr; i=i->proximo)
    {   
        auto procurar=cache.getItem(std::stoi(i->valores.idFilme));
        if (procurar!=nullptr)
        {
            cache.aumentarContador(std::stoi(i->valores.idFilme));
            cache.aumentarContador(std::stoi(i->valores.idFilme));
            u.Tirar(i);
        } 
    }
    
    cout<<" \n\n\n"<<endl;

    cout<<" -----------------------------------"<<endl;
    cout<<"|Melhores filmes para o novo usuario|"<<endl;
    cout<<" -----------------------------------"<<endl;

    auto recomendacoes2{AnalizarFilmes(kmelhores,u,k)};

    cout<<" \n\n\n"<<endl;

    cout<<" ----------------------------------"<<endl;
    cout<<"|     Colocando dados no Cache     | "<<endl;
    cout<<" ----------------------------------"<<endl;

     for (auto i = u.getPrimeiro(); i !=nullptr; i=i->proximo)
    {
        cache.inserirCache(std::stoi(i->valores.idFilme),recomendacoes2);
        cache.aumentarContador(std::stoi(i->valores.idFilme));
    }
    

    cout<<" \n\n\n"<<endl;

    cout<<" ---------------------------------"<<endl;
    cout<<"|       Testando novo Cache       |"<<endl;
    cout<<" ---------------------------------"<<endl;

    cout<<"Verificando conteudo de um novo item do cache:  "<<cache.getItem(88)->filmes.getPrimeiro()->valores.id<<endl;
    cout<<"Inserindo item aleatorio no cache:           ";
    cache.inserirCache(1522222555,recomendacoes2);
    cout<<"Verificando dados do item aleatorio criado no cache:  "<<cache.getItem(1522222555)->filmes.getPrimeiro()->valores.id<<endl;
    
    cout<<" \n\n\n"<<endl;
 }