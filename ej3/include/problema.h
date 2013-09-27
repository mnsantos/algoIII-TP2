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

struct Grafo{
	vector< vector<int> > adyacencias;
	int _cantNodos;	
};

struct Problema{
	void resolver();
	Problema (istream&);
	void mostrarResultado (ostream&);
	void mostrarMatriz();
	vector<int> dijkstra(int);
	
	Grafo g;
	int _cantFabricas;
	int _cantClientes;
	int _cantRutas;
};

#endif
