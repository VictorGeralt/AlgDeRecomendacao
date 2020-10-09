#include "Tokenizador.hpp"


using namespace std;
int main(){
    
	char delimitador[] = ","; 
	

    FILE *arq;
    char buffer [100];
    Lista<float> *lista = new Lista<float>();

    lista->setDelimitador(delimitador);
    

    arq = fopen ("netflix.csv" , "r");
      if (arq == NULL) perror ("Error opening file");
    else
    {
      while ( ! feof (arq) )
      {
        if ( fgets (buffer , 100 , arq) == NULL ) break;
        lista->tokenizer(fgets (buffer , 100 , arq));
      }
      fclose (arq);
    }
	 
    cout<<lista->getToken()<<"\n";
    cout<<lista->getToken()<<"\n";
    cout<<lista->getToken()<<"\n";
    cout<<lista->getToken()<<"\n";

    
    return 0;
}