#include "../include/problema.h"

using namespace std;

Problema::Problema(istream& is){
	is >> _cantFabricas >> _cantClientes >> _cantRutas;
	g._cantNodos = _cantFabricas + _cantClientes;
	g.adyacencias.resize(g._cantNodos);
	for (int i=0;i<g.adyacencias.size();++i){
		g.adyacencias[i].resize(g._cantNodos,-1);
		g.adyacencias[i][i]=0;
	}
	int e1; int e2; int l;
	for (int i=0;i<_cantRutas;++i){
		is >> e1 >> e2 >> l;
		g.adyacencias[e1-1][e2-1]=l;
		g.adyacencias[e2-1][e1-1]=l;
	}
}

void Problema::mostrarMatriz(){
	for (int i=0;i<g.adyacencias.size();++i){
		for (int j=0;j<g.adyacencias[i].size();++j){
			if (j==g.adyacencias[i].size()-1){
				if (g.adyacencias[i][j]==-1 || g.adyacencias[i][j]>=10) cout<<g.adyacencias[i][j]<<endl;
				else cout<<" "<<g.adyacencias[i][j]<<endl;
			}
			else{
				if (g.adyacencias[i][j]==-1 || g.adyacencias[i][j]>=10) cout<<g.adyacencias[i][j]<<" ";
				else cout<<" "<<g.adyacencias[i][j]<<" ";
			}
		}
	}
}

void Problema::mostrarResultado (ostream& os){
	
}

void Problema::resolver(){
	vector<int> a = dijkstra(1);
	for (int i=0;i<a.size();++i){
		cout<<a[i]<<" ";
	}
}

vector<int> Problema::dijkstra(int nodo){
	vector<int> dist;
	dist.resize(g._cantNodos,1000);
	dist[nodo]=0;
	priority_queue<int> q;
	q.push(nodo);
	int u;
	while (!q.empty()){
		u=q.top();
		q.pop();
		for (int i=0;i<g.adyacencias[u].size();++i){
			if (g.adyacencias[u][i]!=-1 && g.adyacencias[u][i]!=0){
				if (dist[i] > dist[u] + g.adyacencias[u][i]){
					dist[i] = dist[u] + g.adyacencias[u][i];
					q.push(i);
				}
			}
		}
	}
	return dist;
}
