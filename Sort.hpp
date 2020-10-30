#include"Lista.hpp"
#include"netflix.hpp"



void Sort(Lista<netflix> &n) {
    
   for (auto i=n.getPrimeiro();i !=n.getUltimo()->anterior;i=i->proximo){
       
    auto jMin = i;   
    for (auto j = i->proximo; j != n.getUltimo()->proximo; j=j->proximo){
          
        if (std::stoi(j->valores.idUser) < std::stoi(jMin->valores.idUser))
        {
            
            jMin = j;
        }
    }
    if (jMin != i) 
    {
        auto aux=i->valores;
        i->valores=jMin->valores;
        jMin->valores=aux;
        
    }

}
}