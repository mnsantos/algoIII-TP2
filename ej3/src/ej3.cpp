#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is >> _cantFabricas >> _cantClientes >> _cantRutas;
	g._cantNodos = _cantFabricas + _cantClientes;
	g.nodos.resize(g._cantNodos);
	int e1; int e2; int l;
	for (int i=0;i<_cantRutas;++i){
		is >> e1 >> e2 >> l;
		g.nodos[e1-1].adyacentes.push_back(make_pair(e2-1,l));
		g.nodos[e2-1].adyacentes.push_back(make_pair(e1-1,l));
	}
}

void Grafo::mostrarGrafo(ostream& os){
	for (int i=0;i<_cantNodos;++i){
		for (int j=0;j<nodos[i].adyacentes.size();++j){
			os<<"("<<i+1<<","<<nodos[i].adyacentes[j].first+1<<", p:"<<nodos[i].adyacentes[j].second<<") ";
		}
	}
	cout<<endl;
}

void Problema::mostrarResultado (vector<arista>& res,ostream& os){
	int costo = 0;
	for (int i=0;i<res.size();++i){
		costo+=res[i].l;
	}
	os<<costo<<" "<<res.size();
	for (int i=0;i<res.size();++i){
		os<<" "<<res[i].e1+1<<" "<<res[i].e2+1;
	}
	os<<endl;
}

vector<arista> Problema::resolver(){
	priority_queue<arista> cola;
	arista v;
	int e2; int l;
	for (int i=0;i<_cantFabricas;++i){
		for (int j=0;j<g.nodos[i].adyacentes.size();++j){
			e2 = g.nodos[i].adyacentes[j].first;
			l = g.nodos[i].adyacentes[j].second;
			if (e2>=_cantFabricas){
				v.e1 = i; v.e2 = e2; v.l = l;
				cola.push(v);
			}
		}
	}
	return prim(cola);
}

vector<arista> Problema::prim(priority_queue<arista>& cola){
	vector<bool> marcados (g._cantNodos);
	arista u;
	arista v;
	vector<arista> res;
	for (int i=0;i<_cantClientes;++i){
		u = obtenerMin(marcados,cola);
		res.push_back(u);
		for (int j=0;j<g.nodos[u.e2].adyacentes.size();++j){
			if (u.e1!=g.nodos[u.e2].adyacentes[j].first){
				v.e1 = u.e2;
				v.e2 = g.nodos[u.e2].adyacentes[j].first;
				v.l = g.nodos[u.e2].adyacentes[j].second;
				cola.push(v);
			}
		}
	}
	return res;
}

arista Problema::obtenerMin(vector<bool>& marcados, priority_queue<arista>& cola){
	int e1; int e2;
	arista u;
	while (true){
		u = cola.top();
		cola.pop();
		if (u.e2 < _cantFabricas){
			if (!marcados[u.e1]){
				marcados[u.e1] = 1;
				return u;
			}
		}
		else if (!marcados[u.e1] || !marcados[u.e2]){
			marcados[u.e1] = 1;
			marcados[u.e2] = 1;
			return u;
		}
	}
}
