#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;

struct nodo{
	int anterior; //para reconstruir la respuesta
	int maquina; //en q maquina pongo el j
	int costo;
	
	nodo(int cost){
		costo=cost;
	}
	
	nodo(const nodo& c){
		anterior= c.anterior;
		costo= c.costo;
	}
};

struct Problema{
	int cantTrabajos;
	vector< vector<int> > costos; //(costos[i])[j] es el costo de hacer el trabajo i despues del j
	
	vector< vector< nodo> > dp;  //matriz de n*n (0<=i<n-1 , 0<=j<=n pero la columna 0 nunca la uso, solo es para acomodar el indexado) [cantTrabajos][cantTrabajos+1]
	int costo_final;
	list<int> solucion;
	
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
