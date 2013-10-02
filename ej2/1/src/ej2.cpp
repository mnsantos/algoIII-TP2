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
		if(n1 > n2){
			Enlace arista(nodo2, nodo1, peso); //hago q los nodos de los enlaces esten ordenaditos
		}else{
			Enlace arista(nodo1, nodo2, peso)
		}
		grafo[nodo1.indice][nodo2.indice](arista);	//cargo los parametros en la mitad de la arista (supongo q en la superior)
	}
}





void Problema::mostrarResultado (ostream& os){
	
	for(int i = 0; i < _cantServidores; i++){
		os<< "(" << arbol[i].nodo1 << ", " << arbol[i].nodo2 << ", " << arbol[i].peso << ")" << endl;
	}
}	




void Problema::pseudoPrim(){

	vector<Enlace> monton; //para obtener aristas livianas en O(1)
	//vector<Enlace> arbol; //el AGM ...teoricamente
	bool comparar (Enlace i, Enlace j){return (i.peso < j.peso);}  //de mayor a menor pues obtengo el ultimo en O(1)
	Servidor k = grafo[0][1].nodo1 ; //este ndo es el de indice 1, esta en toda la primer fila del grafo

	for(int i = 0; i < _cantServidores; i++){  //hasta formar un arbol (n-1 veces)
		
		for(int j = k.indice+1; j < _cantServidores;j++){  // a lo sumo n-1 veces
			if(grafo[k.indice][j].peso != -1){		//cargo el monton con aristas de nodo k, desde mitad sup de matriz
				monton.push_back(grafo[i][j]);
			}
		}


		sort(monton.begin, monton.end, comparar);

		
		while(noTermine){  //busco la arista
			k.mark(); //marco el nodo 

			if(!(monton.end().nodo1.marcado) && (monton.end().nodo2.marcado) ){ //
				auxiliar.push_back(monton.end());
				k = monton.end();
				noTermine = false;
			}
 			if((monton.end().nodo1.marcado) && !(monton.end().nodo2.marcado)){
		
				auxiliar.push_back(monton.end());
				k = monton.end();
				noTermine = false; 
		 	}									
			monton.pop_back(); //saco la arista elejida, sea la q quiera o no
		}		
	}
}
