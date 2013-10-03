#include <iostream>

using namespace std;

int main()
{	
	int cant_datos, cant_paquetes;
	unsigned long long int ciclos;
	int cant_casos;
	cin>> cant_datos;
	cin>> cant_casos;
	
	unsigned long long int promedios[cant_casos+1];
	for(int i=0; i<cant_casos; i++){	
		promedios[i]= 0;
	}
	
	for(int i=0; i<cant_datos*cant_casos; i++){
		cant_paquetes=0;
		ciclos=0;
		cin>> cant_paquetes;
		cin>> ciclos;
		promedios[cant_paquetes-2] += ciclos; 	//sumo todos los valores de esa cant de paquetes
	}
	
	for(int i=0; i<cant_casos; i++){	//para cada caso
		promedios[i]= promedios[i]/cant_datos; 	//divido por la cant de datos (saco el promedio)
	}
	
	for(int i=0; i<cant_casos; i++){	//para cada caso
		cout<< i+1<< " " << promedios[i]<< endl;	//imprimo la cant de paquetes y el promedio
	}
	
	return 0;
}
