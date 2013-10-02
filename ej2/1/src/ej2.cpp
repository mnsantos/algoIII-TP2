#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is >> _cantServidores >> _cantEnlaces;
	int n1,n2;
	//cout << n1 << " "<< n2 << endl; //tienen que ser cero
	Servidor aux(n1);
	Enlace inicial(aux, aux,-1);
	for(int i=0; i< _cantEnlaces; i++){
		for(int j=0; j< _cantNodos){	//inicializo con Enlaces (o aristas) de peso
			grafo[i][j]= inicial;	//-1 para distinguirlos de las aristas de entrada
		}
	}

	for(int i = 1; i <= _cantEnlaces; i++){
		is>>n1;
		is>>n2;
		is>>peso;
		Servidor nodo1(n1);
		Servidor nodo2(n2);

		Enlace arista(nodo1, nodo2, peso);

		grafo[nodo1.indice][nodo2.indice](arista);	//cargo los parametros en toda
		grafo[nodo2.indice][nodo1.indice](arista);	//la matriz solo por ahora
	}
}





void Problema::mostrarResultado (ostream& os){
}




void Problema::pseudoPrim(){

	vector<Enlace> monton;
	vector<Enlace> arbol;
	bool comparar (Enlace i, Enlace j){return (i.peso < j.peso);}  //de mayor a menor pues obtengo el ultimo en O(1)
	
	for(int i = 0; i < _cantServidores; i++){  //hasta formar un arbol (n-1 veces)
		
		for(int j = i+1; j < _cantServidores;j++){  // a lo sumo n-1 veces
			if(grafo[i][j].peso != -1){		//cargo el monton con aristas de nodo k
				monton.push_back(grafo[i][j]);
			}
		}
		sort(monton.begin, monton.end, comparar);
		if( !(monton.end().nodo1.marcado) || (monton.end().nodo2.marcado) ){
		
			auxiliar.push_back(monton.end());
			marcar();
		}else{
			
			
		} 										

		monton.pop_back(); //saco la arista elejida













	
		
	}
}
