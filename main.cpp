#include "Lista.hpp"
#include <fstream>
#include <iostream>
#include "Comparador.hpp"


using namespace std;
int main(){
    
    Lista<neftlix> n;
	char delimitador[] = ","; 
    fstream fs("netflix.csv");
    string s;
    int ID,k;
    Comparador c;
    

    while (getline(fs,s))
    {
        n.colocarNoUltimo(tokenizar(s.c_str(),","));
    }
    
    ponta<neftlix> *verificador= n.getPrimeiro();

    while (verificador!=nullptr)
    {
        cout<<verificador->valores.idUser<<"-";
        cout<<verificador->valores.idFilme<<"-";
        cout<<verificador->valores.Nota<<"\n";
        verificador=verificador->proximo;
    }
    ponta<neftlix> v[5]{*verificador,*verificador,*verificador,*verificador,*verificador};
    c.criarUsuarios(v);

    return 0;
}