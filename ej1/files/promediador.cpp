#include <iostream>

#define casos 90

using namespace std;

int main()
{	
	int cant_datos, cant_paquetes;
	unsigned long long int ciclos;
	cin>> cant_datos;
	
	unsigned long long int promedios[casos+1];
	for(int i=0; i<casos; i++){	
		promedios[i]= 0;
	}
	
	for(int i=0; i<cant_datos*casos; i++){
		cant_paquetes=0;
		ciclos=0;
		cin>> cant_paquetes;
		cin>> ciclos;
		promedios[cant_paquetes-1] += ciclos; 	//sumo todos los valores de esa cant de paquetes
	}
	
	for(int i=0; i<casos; i++){	//para cada caso
		promedios[i]= promedios[i]/cant_datos; 	//divido por la cant de datos (saco el promedio)
	}
	
	for(int i=0; i<casos; i++){	//para cada caso
		cout<< i+1<< " " << promedios[i]<< endl;	//imprimo la cant de paquetes y el promedio
	}
	
	return 0;
}
