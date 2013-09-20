#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	int costoij;
	is>> cantTrabajos;
	vector<int> vacio;
	vector<int> costos;
	
	trabajos.push_back(vacio); //pusheo el vector vacio para tener ocupada la pos 0 (para no hacer lio con los indices de los trabajos)
	for(int i=1; i<=cantTrabajos; i++){
		costos= vacio;
		
		for(int j=0; j<i; j++){
			is>> costoij;
			costos.push_back(costoij);
		}
		trabajos.push_back(costos);
	}
}

void Problema::mostrarResultado (ostream& os){
	os<< costo_final << " ";
	os<< trabajos_finales.size() << " ";
	
	for(int i=0; i<trabajos_finales.size(); i++){
		os<< trabajos_finales[i];
		if(i!= trabajos_finales.size()-1) os<< " ";
	}
}

void Problema::resolver(){
	nodo aux(trabajos[1][0]); //creo un nodo con el costo= costo de hacer t1 primero
	aux.m1.push_back(1); //pongo el t1 en la maquina 1 (asumo q m1 es siempre donde pongo el t1)
	aux.m2.push_back(0); //pongo nada en la maquina 2
	solucion.push_back(aux);
	
	
	for(int i=2; i<=cantTrabajos; i++){		//recorro los trabajos
		vector< nodo > solucion_parcial;
		
		for(int j=0; j<solucion.size(); j++){ //recorro las pos de solucion
			//si el ti va en m1
			nodo copia(solucion[j]);
			copia.costo += trabajos[i][copia.m1.back()];	//al costo q salia hasta ahora le sumo el costo de poner ti dsp del ultimo trabajo en m1
			copia.m1.push_back(i);	//pongo ti como ultimo trabajo agregado a m1
			solucion_parcial.push_back(copia); //agrego el nodo a la solucion parcial
			
			//si el ti va en m2
			nodo copia2(solucion[j]);
			copia2.costo += trabajos[i][copia2.m2.back()];	//al costo q salia hasta ahora le sumo el costo de poner ti dsp del ultimo trabajo en m2
			copia2.m2.push_back(i);	//pongo ti como ultimo trabajo agregado a m2
			solucion_parcial.push_back(copia2); //agrego el nodo a la solucion parcial
		}
		
		solucion= solucion_parcial; //actualizo la solucion y paso al prox trabajo
	}
	
	//cuando salgo de aca tengo en solucion todos los costos de todas las combinaciones
	int combinacion_final= 0; //para no andar copiando el vector con los trabajos
	costo_final= solucion[0].costo;
	
	for(int j=1; j<solucion.size(); j++){ //recorro solucion
		if(solucion[j].costo < costo_final){ //si la solucion j es mas barata q la actual
			costo_final= solucion[j].costo;
			combinacion_final= j;
		}
	}
	trabajos_finales= solucion[combinacion_final].m1;
}
