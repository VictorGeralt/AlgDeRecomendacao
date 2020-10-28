#ifndef Lista_hpp
#define Lista_hpp

#include <iostream>


template <typename T>
struct ponta
{
    T valores;
    struct ponta *proximo;
    struct ponta *anterior;
};



template<typename T>
class Lista{
private:

    ponta<T> *primeiro;
    ponta<T> *ultimo;

public:


    Lista();
    ~Lista();

    void colocarNoUltimo(T valor);
    void tirarOUltimo();
    int getTamanho();
    
    ponta<T> *getVetor();
    ponta<T> *getPrimeiro();
    ponta<T> *getUltimo();

};


template<typename T>
Lista<T>::Lista(){
    ponta<T> *Ponta= new ponta<T>();
    Ponta -> valores=T();
    Ponta -> proximo= nullptr;
    Ponta -> anterior= nullptr;

    primeiro=Ponta;
    ultimo=Ponta;
}


template<typename T>
Lista<T>::~Lista(){
    while (ultimo!=nullptr)
    {
        this->tirarOUltimo();
    }
    
}


template<typename T>
void Lista<T>::colocarNoUltimo(T valor){
    ponta<T> *temp= new ponta<T>();
    temp->valores=valor;
    ultimo->proximo=temp;
    temp->anterior=ultimo;
    ultimo=temp;
    temp->proximo=nullptr;
    
}

template<typename T>
void Lista<T>::tirarOUltimo(){
    ponta<T> *temp=ultimo;
    ultimo=ultimo->anterior;
    delete temp;
}




template<typename T>
int Lista<T>::getTamanho(){
    int tam=0;
    for(auto i = getPrimeiro() ;  i!=ultimo->proximo ; i=i->proximo){
        tam++; 
    }
std::cout<<tam<<"\n";

return tam;
};

template<typename T>
ponta<T> *Lista<T>::getVetor(){
    ponta<T> *vetor[getTamanho()];
    int j=0;
    for(ponta<T> *i = getPrimeiro() ;  i!=ultimo->proximo ; i=i->proximo){
         vetor[j]=i;
        
        std::cout<<j<<"  "<<vetor[j]<<"\n";
        j++;
    }

        return *vetor;
};




template<typename T>
ponta<T> *Lista<T>::getPrimeiro(){
    return primeiro->proximo;
}

template<typename T>
ponta<T> *Lista<T>::getUltimo(){
    return ultimo->anterior;
}


#endif