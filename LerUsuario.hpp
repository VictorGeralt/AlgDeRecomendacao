#include "usuario.hpp"
#include "Lista.hpp"
#include <fstream>
#include <string>
#pragma once

Lista <usuario> getUsuario(){
    
    Lista <usuario> u;

    std::fstream fs("ParaComparar.csv");
    std::string s;
    
    

    while (getline(fs,s))
    {
        u.colocarNoUltimo(tokenizarUsuario(s.c_str(),","));
    }

    return std::move(u);
}