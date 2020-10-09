#ifndef HEADER_TOKENIZER
#define HEADER_TOKENIZER


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;


template <typename T>
struct ponta
{
    T valores;
    struct ponta *next;
};



template<typename T>
class Lista{

private:

    ponta<T> *primeiro;
    ponta<T> *ultimo;
    const char *delimitador;
    const char *token;
    string::size_type sz;

public:

    Lista();

    void tokenizer(char linha[]);
    void setDelimitador(char *d);
    

    T getToken();
};

template<typename T>
Lista<T>::Lista(){
    ponta<T> *Ponta= new ponta<T>();
    Ponta -> valores=T();
    Ponta -> next= NULL;

    primeiro=Ponta;
    ultimo=Ponta;
}

template<typename T> 
void Lista<T>::setDelimitador(char *d){
	delimitador = d;
}

template<typename T> 
void Lista<T>::tokenizer(char linha[]){
	token = strtok(linha, delimitador);
}


template<typename T> 
T Lista<T>::getToken(){
	T v = stod(token, &sz);
	return v;
}

#endif