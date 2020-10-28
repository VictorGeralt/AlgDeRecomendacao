#ifndef Comparador_hpp
#define Comparador_hpp
#include "Lista.hpp"
#include "netflix.hpp"
#include "usuario.hpp"
#include <iostream>
#include <string> 



class Comparador{
public:


    
    Comparador();

    void criarUsuarios(ponta<neftlix> v[]);
    void comparacao(int ID);
    void maisProximos(int k);

};

Comparador::Comparador(){
}

void Comparador::criarUsuarios(ponta<neftlix> v[]){
    int tam=0;
    
    for(size_t i=0;i<2;i++){
        char Cuser[3];
        strcpy(Cuser,v[i].valores.idUser);

        
        if(std::stoi(Cuser)>tam){
           tam=std::stoi(Cuser);
        } 
    
    
    }
    
}

void Comparador::comparacao(int ID){

    
}

void Comparador::maisProximos(int k){

    
}


#endif