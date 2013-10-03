#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	
	is>> cantNodos;
	
	is>> cantEnlaces; //el formato por ahora es: cant nodos, cantidad de enlaces, i1 f1, i2 f2, i3 f3 in fn, i y f son nodos
	
	arbol.resize(cantNodos+1); // el de la posicion cero no lo uso
	
	for(int i=1; i <= cantNodos+1 ; i++){
		arbol[i].idNodo = i;
	}
	
	
	int primerNodo, segundoNodo;
	for(int i=0; i < cantEnlaces; i++){
		is>> primerNodo;
		is>> segundoNodo;
		
		arbol[primerNodo].indicesHijos.push_back (segundoNodo); //agrego a cada uno como hijo del otro, es bidireccional
		arbol[segundoNodo].indicesHijos.push_back (primerNodo);
		
	}

}

void Problema::mostrarResultado (ostream& os){
	os << master<< endl;
	os << ram1 << " " << ram2 << " " << rama_larga1 << " " << nodoOriginal; //imprimo long de rama1 y 2, dsp el nodo hacia la rama mas larga y el nodo original (pertenece al camino mas largo pero no necesariamente es el centro)
	
}

void Problema::resolver(){
	int nroNodo= cantNodos /2; //elijo el nodo del centro para arrancar, podria ser random;
	int no_Sirve = recursion(nroNodo, 0); //le paso cero pq no tiene padre y 0 no es un nodo posible
	//ahora la estructura esta actualizada con todos sus datos, me falta recorrerla buscando el maximo en suma de longitudes
	int indice_Max_Camino, suma, sumaMax=0;
	int r1, r2;
	
	for(int i=0; i < cantNodos+1; i++){ //ojo el indice cantNodos
		suma= arbol[i].sumaLongitudes;
		if(suma > sumaMax){
			sumaMax=suma;
			indice_Max_Camino=i;
			
		}
	}
	
	r1= arbol[indice_Max_Camino].longRamaLarga1;
	r2= arbol[indice_Max_Camino].longRamaLarga2;
	//nodo_Rama_Larga = arbol[indice_Max_Camino].indiceRamaLarga1;
	
	
	//borrar dsp es para probar
	ram1=r1;
	ram2=r2;
	rama_larga1=arbol[indice_Max_Camino].indiceRamaLarga1;
	nodoOriginal= indice_Max_Camino;
	//prueba
	
	
	int nodo_Camino_Max = indice_Max_Camino;
	
	master= nodo_Camino_Max; //master empieza valiendo el nodo que obtuve antes
	while( r1!=r2 && (r1-1)!= r2){ //si hay una diferencia entre ramas mayor a 1 avanzo por la rama mas larga
		master=arbol[master].indiceRamaLarga1;
		r1--; //siempre me muevo por la rama
		r2++;
	}
	
}

int Problema::recursion(int nroNodo, int idPadre){
	int rama1=0, rama2=0, rama=0, nodo_rama1=0;  //inicializo las variables
	
	
	for (int i=0; i < arbol[nroNodo].indicesHijos.size(); i++){//recorro los hijos del nodo actual
		int hijo= arbol[nroNodo].indicesHijos[i]; //levanto el nodo hijo que uso para calcular en cada iteracion, hasta que no quedan mas hijos por ver
		
		if(hijo != idPadre){ //tengo que ver que no vuelva hacia el padre, pq en indicesHijos guardo todos los nodos que se conectan
			rama = recursion( hijo, nroNodo); // calcula la rama mas larga yendo por uno de sus hijos
			
			if(rama1 < rama){//rama1 tiene la rama mas larga, rama2 la segunda mas larga
				rama2=rama1;
				rama1=rama;
				nodo_rama1=hijo; //nodo_rama1 guarda hacia que nodo tengo q	ir para encontrar la rama mas larga
			}else{
				if(rama2 < rama){
					rama2=rama;
				}
			}
		}
	}
	//actualizo datos del nodo actual
	arbol[nroNodo].longRamaLarga1= rama1;
	arbol[nroNodo].longRamaLarga2= rama2;
	arbol[nroNodo].sumaLongitudes= rama1 + rama2;
	arbol[nroNodo].indiceRamaLarga1= nodo_rama1;
	
	return (rama1 +1); // le sumo el enlace que une al nodo actual con su padre
	

}//fin recursion 
