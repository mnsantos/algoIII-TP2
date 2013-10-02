#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main()
{
	srand (time(NULL));
	
	int cantidad_max_trabajos;
	cin>> cantidad_max_trabajos;
	
	int varianza;
	cin>> varianza;
	
	for (int i=1; i<=cantidad_max_trabajos; ++i){ //para cada instancia
		cout << i << endl;						  //imprime la cant de trabajos
		
		for (int j=1; j<=i; j++){				  //para cada linea (cada trabajo)
			for(int k=0; k<j; k++){				  //imprime los costos desde 0 hasta j-1
				int costo= rand() % varianza + 1;
				cout<< costo;
				if(k!=j-1) cout<< " ";
			 }
			 cout<< endl;
		}
		
	}
	cout <<"0";
	return 0;
}
