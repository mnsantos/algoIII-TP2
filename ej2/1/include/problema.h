#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <queue>

using namespace std;

struct Enlace{
	int nodo1;
	int nodo2;
	int costo;
	
	Enlace();
	Enlace(int nod1, int nod2, int peso):nodo1(nod1),nodo2(nod2),costo(peso){}
	Enlace(const Enlace& e){
		nodo1=e.nodo1;
		nodo2=e.nodo2;
		costo=e.costo;
	}
};

struct Servidor{ //o nodo
	int indice;
	bool marcado;
	vector<Enlace> adyacentes;
	
	Servidor(int ind):indice(ind),marcado(false){} 
	Servidor():indice(0),marcado(false){}
	void marcar(){marcado = true;}
};

inline bool operator< (Enlace a,Enlace b){return a.costo>b.costo;}

struct Problema{
	int _cantServidores;	
	int _cantEnlaces;
	
	vector< Servidor> servidores;
	vector< Enlace > enlaces;
	
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
	Enlace obtenerMin(priority_queue<Enlace>& cola);
};

#endif
