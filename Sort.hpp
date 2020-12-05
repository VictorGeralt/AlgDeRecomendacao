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


void CountSort(std::pair<int,float>*a, int n, int exp)
{  
  std::pair<int,float> result[n];
   int i, count[10] = {0};
 
  
  for (i =0; i <n; i++)
    count[static_cast<int>(a[i].second / exp) % 10]++;
 
  
  for (i =1; i<10; i++)
    count[i] += count[i-1];
 
  
  for (i =n-1; i>= 0; i--)
  {
    result[count[static_cast<int>(a[i].second / exp) % 10] - 1] = a[i];
    count[static_cast<int>(a[i].second / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}



  void radixsort(std::pair<int,float>*a, int n,int max)
    {
    int exp, i{max};
    
    for (exp = 1; i/exp > 0; exp *= 10)
        CountSort(a, n, exp);
    }
    

