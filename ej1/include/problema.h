#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;

struct nodo{
	vector< int > m1; //trabajos en maquina 1
	vector< int > m2; //trabajos en maquina 2
	int costo;
	
	nodo(int cost){
		costo=cost;
	}
	
	nodo(const nodo& c){
		m1= c.m1;
		m2= c.m2;
		costo= c.costo;
	}
};

struct Problema{
	int cantTrabajos;
	vector< vector<int> > trabajos; //(trabajos[i])[j] es el costo de hacer el trabajo i despues del j
	
	vector< nodo > solucion; //[(trabajos en m1, trabajos en m2, costo hasta este momento), ... ]
	int costo_final;
	vector<int> trabajos_finales;
	
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
