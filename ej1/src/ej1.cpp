#include "../include/problema.h"

#define infinito 1e9;

using namespace std;

Problema::Problema(istream& is){
	int costoij;
	is>> cantTrabajos;
	vector<int> vacio;
	vector<int> aux;
	
	costos.push_back(vacio); //pusheo el vector vacio para tener ocupada la pos 0 (para no hacer lio con los indices de los trabajos)
	for(int i=1; i<=cantTrabajos; i++){
		aux= vacio;
		
		for(int j=0; j<i; j++){
			is>> costoij;
			aux.push_back(costoij);
		}
		costos.push_back(aux);
	}
}

void Problema::mostrarResultado (ostream& os){
	//~ //mostrar matriz dp
	//~ for(int i=0; i<cantTrabajos; i++){
		//~ for(int j=1; j<=cantTrabajos; j++){
			//~ os<< dp[i][j].costo << " ";
		//~ }
		//~ os<< endl;
	//~ }
	// C k i_1 ... i_k
	os<< dp[nodo_solucion.first][nodo_solucion.second].costo << " ";
	os<< dp[nodo_solucion.first][nodo_solucion.second].m1.size() << " ";
	
	for(int i=0; i< dp[nodo_solucion.first][nodo_solucion.second].m1.size(); i++){
		os<< dp[nodo_solucion.first][nodo_solucion.second].m1[i];
		if(i!= dp[nodo_solucion.first][nodo_solucion.second].m1.size()-1) os<< " ";
	}
}

void Problema::resolver(){
	//inicializacion
	nodo inf( 1e9 );
	nodo no_calculado(-1);
	
	for(int i=0; i< cantTrabajos; i++){ //0<=i<n
		vector< nodo> row;
		for(int j=0; j<= cantTrabajos; j++){ //0<=j<=n matriz de n+1 columnas pero no uso la 0
			if(i>=j || j==0) row.push_back(inf); //si la pos es invalida pone un infinito
			else row.push_back(no_calculado);	//si es valida la pone como no calculada
		}
		dp.push_back(row);
	}
	
	dp[0][1]= costos[1][0]; //caso base
	dp[0][1].m2.push_back(1);
	//calculo
	for(int j=2; j<=cantTrabajos; j++){
		for(int i=0; i<=j-1; i++){
			
			if(i==j-1){
				int min= 1e9;
				int kminimo;
				for(int k=0; k<=j-2; k++){
					if( dp[k][j-1].costo + costos[j][k] < min){
						min= dp[k][j-1].costo + costos[j][k];
						kminimo= k;
					}
				}
				dp[i][j].costo = min;
				dp[i][j].m1= dp[kminimo][j-1].m2;
				dp[i][j].m2= dp[kminimo][j-1].m1;
				dp[i][j].m2.push_back(j);
				
			}
			else{
				dp[i][j].costo= dp[i][j-1].costo + costos[j][j-1];
				dp[i][j].m1= dp[i][j-1].m1;
				dp[i][j].m2= dp[i][j-1].m2;
				dp[i][j].m2.push_back(j);
			}
		}
	}
	//fin, falta encontrar el minimo de la ultima columna
	int min= 1e9;
	nodo_solucion.second=cantTrabajos;
	
	for(int i=0; i< cantTrabajos; i++){
		if(dp[i][cantTrabajos].costo < min){ 
			min= dp[i][cantTrabajos].costo;
			nodo_solucion.first= i;
		}
	}
}
