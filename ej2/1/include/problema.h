#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cassert>
#include <algorithm>

using namespace std;


struct Servidor{ //o nodo
	int indice;
	bool marcado;
	Servidor(int ind){indice = ind; marcado = false;} 
	void marcar(){marcado = true;}
};


struct Enlace{ //o arista
	Servidor nodo1;
	Servidor nodo2;
	int peso;
	Enlace(Servidor n1, Servidor n2, int p){nodo1 = n1; nodo2 = n2; peso = p;}
};


struct Problema{
	int _cantServidores;	
	int _cantEnlaces;
	
	vector<Enlace> arbol; //donde devulvo el resultado
	vector<vector<Enlace> > grafo; //matriz 

	void pseudoPrim(); //en vez de resolver, para despues tratar de mezclar con el .2
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
