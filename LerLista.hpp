#include "Lista.hpp"
#include "netflix.hpp"
#include <fstream>
#include <string>



Lista<netflix> GetLista(){
Lista <netflix> n;

std::fstream fs("netflix.csv");
    std::string s;
    
    

    while (getline(fs,s))
    {
        n.colocarNoUltimo(tokenizarLista(s.c_str(),","));
    }

    return std::move(n);
}