#include "Lista.hpp"
#include "netflix.hpp"
#include <fstream>
#include <string>



Lista<netflix> GetData(){
Lista <netflix> n;

std::fstream fs("netflix.csv");
    std::string s;
    
    

    while (getline(fs,s))
    {
        n.colocarNoUltimo(tokenizar(s.c_str(),","));
    }

    return std::move(n);
}