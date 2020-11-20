#include <cstring>
#include <fstream>
#include <string>
#include"Lista.hpp"
#include"netflix.hpp"




 Lista<Lista<netflix>> CriarUsuarios(Lista<netflix> &n){

    Lista<Lista<netflix>> Users;
    Lista<netflix> User;
    int a=0;

    for (auto i=n.getPrimeiro(); i!=nullptr; i=i->proximo)
    {
            netflix aux;
            aux.idFilme=i->valores.idFilme;
            aux.Nota=i->valores.Nota;
            aux.idUser=i->valores.idUser;
            User.colocarNoUltimo(aux);

            if (std::stoi(i->valores.idUser)!=a)
            {
                Users.colocarNoUltimo(User);
                a=std::stoi(i->valores.idUser);
                User.limpar();
            }
            
               
       
    }
    return std::move(Users);
}

