#include <iostream>
#include <stdlib.h>     /* srand, rand */


using namespace std;

int main()
{
	srand (time(NULL));
	
		int cantidad_nodos;
		cin>> cantidad_nodos;
		
		for(int i= 2 ; i<= cantidad_nodos; ++i){
			cout << i << endl; //cantidad de nodos
			cout << i-1 << endl; //cant de aristas
			
			for(int j=1; j < i; j++){
				
				int valor1, valor2;
				valor2 = j; //nodo que agrego
				
				valor1= j + 1; //nodo con quien conecto el valor2, es el siguiente así formo una rama única
					
				cout<< valor1 << " " << valor2 << endl; //imprimo los dos valores
					
			}//fin for j
		}//fin for i
	cout<< "0";
	return 0;
}// fin main
