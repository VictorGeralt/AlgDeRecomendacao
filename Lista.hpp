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
    int tam=0;

public:

    Lista();
    Lista(const Lista<T> &obj);
    Lista(Lista<T> &&obj);
    ~Lista();

    void colocarNoUltimo(T valor);
    void tirarOUltimo();
    int getTamanho();
    
    ponta<T> *getPrimeiro();
    ponta<T> *getUltimo();

    Lista<T> &operator=(const Lista<T> &obj);
    bool operator==(const Lista<T> &obj);
    bool operator!=(const Lista<T> &obj);

    void limpar();
    void TirarOProximo(ponta<T> *aux);
    void Tirar(ponta<T> *aux);

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

template <typename T>
Lista<T>::Lista( Lista<T> &&obj){
    primeiro = obj.primeiro;
    ultimo = obj.ultimo;
    obj.primeiro = nullptr;
    obj.ultimo = nullptr;
    tam = obj.tam;
}

template<typename T>
Lista<T>::Lista(const Lista<T> &obj) 
        {
            
            if (obj.primeiro == nullptr)
            {
                
                primeiro = ultimo = nullptr;
            }else{
                primeiro = new ponta<T>(*obj.primeiro);
                ponta<T> *Ponta = obj.primeiro->proximo;
                ponta<T> *PontaLista= primeiro;
                while (Ponta != obj.ultimo->proximo)
                {
                    
                    PontaLista->proximo = new ponta<T>();

                    PontaLista->proximo->valores=Ponta->valores;
                    PontaLista->proximo->anterior=PontaLista;
                    PontaLista->proximo->proximo=nullptr;


                    PontaLista = PontaLista->proximo;
                    Ponta = Ponta->proximo;

                }
                ultimo = PontaLista;
                tam = obj.tam;

            }

        }

template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &obj){
            if(this != &obj && obj.primeiro != nullptr){
               
                while (ultimo!=nullptr)
            {
                ponta<T>* Ponta = ultimo;
                ultimo = ultimo->anterior;
                delete Ponta;
                Ponta = nullptr;
                tam--; 
            }

            primeiro = ultimo = nullptr;


                primeiro = new ponta<T>(*obj.primeiro);
                ponta<T> *Ponta = obj.primeiro->proximo;
                ponta<T> *PontaLista= primeiro;
                while (Ponta != obj.ultimo->proximo)
                {
                    PontaLista->proximo = new ponta<T>();

                    PontaLista->proximo->valores=Ponta->valores;
                    PontaLista->proximo->anterior=PontaLista;
                    PontaLista->proximo->proximo=nullptr;

                    PontaLista = PontaLista->proximo;
                    Ponta = Ponta->proximo;
                }
                ultimo = PontaLista;
                tam = obj.tam;
            }
            return *this;
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
    tam++;
}

template<typename T>
void Lista<T>::tirarOUltimo(){
    ponta<T> *temp=ultimo;
    ultimo=ultimo->anterior;
    tam--;
    delete temp;
    temp=nullptr;
}




template<typename T>
int Lista<T>::getTamanho(){
return tam;
};





template<typename T>
ponta<T> *Lista<T>::getPrimeiro(){
    return primeiro->proximo;
}

template<typename T>
ponta<T> *Lista<T>::getUltimo(){
    return ultimo;
}

template<typename T>
bool Lista<T>::operator==(const Lista<T> &obj){
            return this->primeiro == obj.primeiro && this->ultimo == obj.ultimo ? true : false;
        }

template<typename T>
bool Lista<T>::operator!=(const Lista<T> &obj){
            return this->primeiro == obj.primeiro && this->ultimo == obj.ultimo ? false : true;
        }



template<typename T>
void Lista<T>::limpar(){
    
    while (ultimo!=primeiro)
            {
                ponta<T>* Ponta = ultimo;
                ultimo = ultimo->anterior;
                delete Ponta;
                Ponta = nullptr;
                tam--; 
            }

}

template<typename T>
void Lista<T>::TirarOProximo(ponta<T> *aux){
    aux->proximo=aux->proximo->proximo;
    tam--;
}

template<typename T>
void Lista<T>::Tirar(ponta<T> *aux){
    aux->anterior->proximo=aux->proximo;
    aux->proximo=aux->proximo->proximo;
    tam--;
}

#endif