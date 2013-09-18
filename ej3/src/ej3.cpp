#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is >> _cantFabricas;
	int cantClientes;
	is >> cantClientes;
	int cantRutas;
	is >> cantRutas;
	
	//_todos.reserve(_cantFabricas+cantClientes+1); no funco!
	nodo nulo;
	for(int j=0; j<_cantFabricas+cantClientes+1; j++){	//esto lo hago para poder agregarlos segun el id despues
		_todos.push_back(nulo);
	}
	
	for(int i=0; i< cantRutas; i++){
		int e1, e2, l;
		is>> e1;
		is>> e2;
		is>> l;
		
		nodo n1= nodo(e1);
		nodo n2= nodo(e2);
		
		pair< int, int > p;
		p.first= e1;
		p.second= l;
		
		n1.vecinos.push_back(p);
		
		p.first= e2;
		n2.vecinos.push_back(p);
		
		_todos[e1]=n1;
		_todos[e2]=n2;
	}
}

void Problema::mostrarResultado (ostream& os){
	os<< _costo_final << " "; //imprimo el costo total (L)
	os<< _rutas_finales.size() << " "; //imprimo la cant de rutas (k)
	
	for(unsigned int i=0; i<_rutas_finales.size();i++){
		os<< _rutas_finales[i].first << " ";
		os<< _rutas_finales[i].second;
		
		if(i!=_rutas_finales.size()-1) os << " ";
	}
}

void Problema::resolver(){
	for(int i=1; i<=_cantFabricas;i++){ //preparo proximos para recorrer todas las fabricas en la 1ª iteracion
		_proximos.push_back(&_todos[i]);
	}
	
	while(_proximos.size()!=0){		//mientras haya proximos para recorrer
	
		for(unsigned int i=0; i<_proximos.size();i++){		//recorro los proximos
			nodo* actual= _proximos.front();			//tomo el primero de ellos
			_proximos.pop_front();
			
			for(unsigned int j=0; j<(actual->vecinos).size();j++){ //recorro sus vecinos
				if(actual->vecinos[j].first > _cantFabricas){ //si el vecino es cliente
				
					if((actual->vecinos[j]).second < _todos[(actual->vecinos[j]).first].precio){ //si el nuevo camino es mejor q el anterior (vecinos es [(id, valor)])
						_todos[(actual->vecinos[j]).first].precio = (actual->vecinos[j]).second; //si es mejor actualizo el precio
						_todos[(actual->vecinos[j]).first].arista = actual->id;						//la arista con la q esta conectado
						_proximos.push_back(&_todos[(actual->vecinos[j]).first]);					//y lo agrego en proximos para luego recorrerlo
					}
				}
			}
		}
	}
	//si sali ya tengo en cada nodo con quien esta conectado y cuanto sale, solo queda sumar todo y contar cuanto es
	_costo_final=0;
	for(unsigned int i=0; i<_todos.size();i++){
		if(_todos[i].arista != 0 & _todos[i].id != -1){ //si esta conectado con alguien
			pair<int, int> p;
			p.first= _todos[i].id;
			p.second= _todos[i].arista;
			
			_rutas_finales.push_back(p); //guardo esa ruta
			_costo_final+= _todos[i].precio; //sumo su precio al costo total
		}
	}
}
