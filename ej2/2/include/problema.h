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
	int idNodo;			//identificador del nodo, es un entero
	int longRamaLarga1; //longitud de la rama mas larga desde este nodo
	int longRamaLarga2; //longitud de la segunda rama mas larga
	int sumaLongitudes;	//suma entre las dos ramas mas largas
	int indiceRamaLarga1;	//indice del nodo por donde continua la rama mas larga
	vector <int> indicesHijos; //una lista de los indices de los hijos (indices del vector de nodos) de este nodo
	
	
	nodo(){//constructor de nodo
		idNodo=0; //el cero no es un id de nodo válido
		longRamaLarga1=0;
		longRamaLarga2=0;
		sumaLongitudes=0;
		indiceRamaLarga1=0;
		
	}
};

struct Problema{
	int cantNodos;	//nro de servidores
	int cantEnlaces;
	int master;
	
	vector <nodo> arbol; //arbol de conexiones
	int ram1, ram2, rama_larga1, nodoOriginal; //son para verificar mas facil en la salida
	
	void resolver();
	int recursion(int nroNodo, int idPadre);
	Problema (istream&);
	void mostrarResultado (ostream&);
};

#endif
