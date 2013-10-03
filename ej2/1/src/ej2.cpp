#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is>> _cantServidores >> _cantEnlaces;
	
	for(int i=0; i< _cantServidores; i++){
		servidores.push_back( Servidor(i));
	}
	
	for(int i=0; i< _cantEnlaces; i++){
		int nodo1, nodo2, peso;
		is>> nodo1 >> nodo2 >> peso;
		nodo1--;
		nodo2--;
		
		servidores[nodo1].adyacentes.push_back(Enlace(nodo1,nodo2,peso));
		
		servidores[nodo2].adyacentes.push_back(Enlace(nodo2,nodo1,peso));
	}
}

void Problema::mostrarResultado (ostream& os){
	os<<_cantServidores<<endl;
	for (int i=0;i<enlaces.size();++i){
		os<<enlaces[i].nodo1+1<<" "<<enlaces[i].nodo2+1<<endl;	
	}
}	

void Problema::resolver(){
	
	Enlace e(1,2,3);
	priority_queue<Enlace> cola;
	servidores[0].marcar();
	for (int i=0;i<servidores[0].adyacentes.size();++i){
		cola.push(servidores[0].adyacentes[i]);
	}
	while(enlaces.size()!=_cantServidores-1){
		e=obtenerMin(cola);
		enlaces.push_back(e);
		for (int i=0;i<servidores[e.nodo2].adyacentes.size();++i){
			if (servidores[e.nodo2].adyacentes[i].nodo2 != e.nodo1){  
				cola.push(servidores[e.nodo2].adyacentes[i]);
			}
		}
	}
}

Enlace Problema::obtenerMin(priority_queue<Enlace>& cola){
	while(true){
		Enlace e= cola.top();
		cola.pop();
		if ((servidores[e.nodo1].marcado && !servidores[e.nodo2].marcado) || (!servidores[e.nodo1].marcado && servidores[e.nodo2].marcado)){
			servidores[e.nodo1].marcar();
			servidores[e.nodo2].marcar();
			return e;
		}
	}
}
