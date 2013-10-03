#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is >> _cantServidores >> _cantEnlaces;
	grafo.resize(_cantServidores);
	/*for (int i=0;i<_cantServidores;++i){
		grafo[i].resize(_cantServidores);
	}*/
	int n1,n2,peso;
	//cout << n1 << " "<< n2 << endl; //tienen que ser cero
	Servidor aux(n1);
	Enlace inicial(aux, aux,-1);
	for(int i=0; i< _cantServidores; i++){
		for(int j=0; j< _cantServidores;j++){	//inicializo con Enlaces (o aristas) de peso
			grafo[i].push_back(inicial);	//-1 para distinguirlos de las aristas de entrada
		}
	}

	for(int i = 1; i <= _cantEnlaces; i++){
		is>>n1;
		is>>n2;
		is>>peso;
		Servidor nodo1(n1-1);
		Servidor nodo2(n2-1);
		Enlace arista(nodo1,nodo2,peso);
		if(n1 > n2){
			arista.nodo1=nodo2;
			arista.nodo2=nodo2;
		}
		grafo[nodo1.indice][nodo2.indice]=arista;	//cargo los parametros en la mitad de la arista (supongo q en la superior)
	}
}






void Problema::mostrarResultado (ostream& os){
	
	for(int i = 0; i < _cantServidores; i++){
		os<< "(" << arbol[i].nodo1.indice << ", " << arbol[i].nodo2.indice << ", " << arbol[i].peso << ")" << endl;
	}
}	




bool comparar(Enlace i, Enlace j){return (i.peso < j.peso);} //de mayor a menor pues obtengo el ultimo en O(1)






void Problema::pseudoPrim(){

	vector<Enlace> monton; //para obtener aristas livianas en O(1)
	Servidor k; //este ndo es el de indice 1, esta en toda la primer fila del grafo

	for(int i = 0; i < _cantServidores-1; i++){  //hasta formar un arbol (n-1 veces)
		for(int j = k.indice+1; j < _cantServidores;j++){  // a lo sumo n-1 veces
			if(grafo[k.indice][j].peso != -1){		//cargo el monton con aristas de nodo k, desde mitad sup de matriz
				monton.push_back(grafo[k.indice][j]);
			}
		}

		sort(monton.begin(), monton.end(), comparar);

		bool noTermine=true;
		while(noTermine){  //busco la arista
			cout<<"hola"<<endl;
			if(!(monton.back().nodo1.marcado) && (monton.back().nodo2.marcado) ){ //
				arbol.push_back(monton.back());
				k = monton.back().nodo1;
				monton.back().nodo1.marcar();
				noTermine = false;
			}
 			if((monton.back().nodo1.marcado) && !(monton.back().nodo2.marcado)){
		
				arbol.push_back(monton.back());
				k = monton.back().nodo1;
				monton.back().nodo2.marcar();
				noTermine = false; 
		 	}									
			monton.pop_back(); //saco la arista elejida, sea la q quiera o no
		}		
	}
}
