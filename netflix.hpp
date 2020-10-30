#include <cstring>
#pragma once

struct netflix
{
    char* idUser;
    char* idFilme;
    char* Nota;
};

netflix tokenizar(const char* linha,const char* delimitador){
   netflix n;
   char texto[strlen(linha)+1];
   strcpy(texto,linha);


   char* tokenizado = strtok(texto, delimitador);
   n.idUser= new char[strlen(tokenizado)+1];
   strcpy(n.idUser,tokenizado);
   
   tokenizado = strtok(NULL, delimitador);
   n.idFilme= new char[strlen(tokenizado)+1];
   strcpy(n.idFilme,tokenizado);

   tokenizado = strtok(NULL, delimitador);
   n.Nota= new char[strlen(tokenizado)+1];
   strcpy(n.Nota,tokenizado);


   return n;
}

