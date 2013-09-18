#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <queue> 
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;

struct nodo{
	vector< pair<int, int> > vecinos; // [(id, valor),...] vector con los ids y los valores de llegar a cada vecino del nodo
	int precio; //precio q sale llegar al nodo
	int arista; //con quien esta conectado (desde donde se llega a este nodo en la sol)
	int id; //pos original del nodo en la lista todos
	
	nodo(){
		precio=-1;
		arista=-1;
		id=-1;
	}
	nodo(int i){
		precio=0;
		arista=0;
		id= i;
	}
};

struct Problema{
	int _cantFabricas;
	vector<nodo> _todos;
	queue<nodo*> _proximos;
	
	vector< pair<int, int> > _rutas_finales;
	int _costo_final;
	
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
