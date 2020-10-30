#include "Lista.hpp"
#include <iostream>
#include "LerArq.hpp"
#include "Sort.hpp"
#include "usuario.hpp"


using namespace std;
int main(){
    
    Lista<netflix> n(GetData());

    
    Sort(n);
    std::cout<<"aaaaa";

    Lista<Lista<usuario>>usuarios(CriarUsuarios(n));

    // cout<<usuarios.getTamanho()<<"\n"<<usuarios.getPrimeiro()->valores.getTamanho();

    // ponta<usuario> *verificador= usuarios.getPrimeiro().getPrimeiro();
    // for (auto i=n.getPrimeiro(); i!=n.getUltimo()->proximo; i=i->proximo)
    // {
    // while (verificador!=nullptr)
    // {
    //     cout<<verificador->valores.idFilme<<"-";
    //     cout<<verificador->valores.Nota<<"\n";
    //     verificador=verificador->proximo;
    // }
    // }

    ponta<netflix> *verificador= n.getPrimeiro();

    while (verificador!=nullptr)
    {
        cout<<verificador->valores.idUser<<"-";
        cout<<verificador->valores.idFilme<<"-";
        cout<<verificador->valores.Nota<<"\n";
        verificador=verificador->proximo;
    }

 
    return 0;
}