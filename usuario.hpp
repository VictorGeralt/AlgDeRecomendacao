#include <cstring>
#include <fstream>
#include <string>
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
            usuario aux;
            aux.idFilme=i->valores.idFilme;
            aux.Nota=i->valores.Nota;
            User.colocarNoUltimo(aux);

            if (std::stoi(i->valores.idUser)!=a)
            {
                Users.colocarNoUltimo(User);
                a=std::stoi(i->valores.idUser);
            }
            
               
       
    }
    return std::move(Users);
}

usuario tokenizarUsuario(const char* linha,const char* delimitador){
   usuario n;
   char texto[strlen(linha)+1];
   strcpy(texto,linha);
   char * null;


   char* tokenizado = strtok(texto, delimitador);
   null= new char[strlen(tokenizado)+1];
   strcpy(null,tokenizado);
   
   tokenizado = strtok(NULL, delimitador);
   n.idFilme= new char[strlen(tokenizado)+1];
   strcpy(n.idFilme,tokenizado);

   tokenizado = strtok(NULL, delimitador);
   n.Nota= new char[strlen(tokenizado)+1];
   strcpy(n.Nota,tokenizado);


   return n;
}

// usuario getUsuario(){
    
//     usuario u;
//     std::fstream fs("ParaComparar.csv");
//     std::string s;
//     getline(fs,s);
//     const char* linha=s.c_str();
//     const char* delimitador=",";
//     char * null;


//    char texto[strlen(linha)+1];
//    strcpy(texto,linha);


//    char* tokenizado = strtok(texto, delimitador);
//    null= new char[strlen(tokenizado)+1];
//    strcpy(null,tokenizado);
   
//    tokenizado = strtok(NULL, delimitador);
//    u.idFilme= new char[strlen(tokenizado)+1];
//    strcpy(u.idFilme,tokenizado);

//    tokenizado = strtok(NULL, delimitador);
//    u.Nota= new char[strlen(tokenizado)+1];
//    strcpy(u.Nota,tokenizado);


//     return u;
// }
