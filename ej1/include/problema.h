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
	vector< int> m1; //ultimo trabajo en maquina 1
	vector< int> m2; //ultimo trabajo en maquina 2
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
	vector< vector<int> > costos; //(costos[i])[j] es el costo de hacer el trabajo i despues del j
	
	vector< vector< nodo> > dp;  //matriz de n*n (0<=i<n-1 , 0<=j<=n pero la columna 0 nunca la uso, solo es para acomodar el indexado) [cantTrabajos][cantTrabajos+1]
	pair< int, int > nodo_solucion;
	
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
