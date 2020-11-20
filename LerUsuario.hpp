#include "usuario.hpp"
#include "Lista.hpp"
#include <fstream>
#include <string>
#pragma once

Lista <netflix> getUsuario(){
    
    Lista <netflix> u;

    std::fstream fs("ParaComparar.csv");
    std::string s;
    
    

    while (getline(fs,s))
    {
        u.colocarNoUltimo(tokenizarNetflix(s.c_str(),","));
    }

    return std::move(u);
}