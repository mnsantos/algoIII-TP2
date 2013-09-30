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

typedef pair<int,int> ady;
struct arista{
	int e1;
	int e2;
	int l;
}; 

inline bool operator< (arista a,arista b){return a.l>b.l;}

struct Nodo{
	vector<ady> adyacentes;
};

struct Grafo{
	vector<Nodo> nodos;
	int _cantNodos;	
	void mostrarGrafo(ostream&);	
};

struct Problema{
	vector<arista> resolver();
	Problema (istream&);
	void mostrarResultado (vector<arista>&,ostream&);
	vector<arista> prim(priority_queue<arista>&);
	arista obtenerMin(vector<bool>&, priority_queue<arista>&);
	
	Grafo g;
	int _cantFabricas;
	int _cantClientes;
	int _cantRutas;
};

#endif
