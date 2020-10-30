#include <cstring>
#include"Lista.hpp"
#include"netflix.hpp"


struct usuario
{
    char* idFilme;
    char* Nota;
};


 Lista<Lista<usuario>> CriarUsuarios(Lista<netflix> &n){

    Lista<Lista<usuario>> Users;
    Lista<usuario> User;
    int a=0;

    for (auto i=n.getPrimeiro(); i!=n.getUltimo()->proximo; i=i->proximo)
    {
        std::cout<<"aaaaa";
            usuario aux;
            aux.idFilme=i->valores.idFilme;
            aux.Nota=i->valores.Nota;
            User.colocarNoUltimo(aux);

            if (std::stoi(i->valores.idUser)!=a)
            {
                std::cout<<"bbbbbbb";
                Users.colocarNoUltimo(User);
                //User.limpar();
                a=std::stoi(i->valores.idUser);
            }
            
               
       
    }
    return std::move(Users);
}