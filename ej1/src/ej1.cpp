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
	
	costo_final= -1;
}

void Problema::mostrarResultado (ostream& os){
	for(int i=0; i<cantTrabajos; i++){
		for(int j=1; j<=cantTrabajos; j++){
			cout<< dp[i][j].costo << " ";
		}
		cout<< endl;
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
	//..
	for(int j=2; j<=cantTrabajos; j++){
		for(int i=0; i<=j-1; i++){
			
			if(i==j-1){
				int min= 1e9;
				for(int k=0; k<=j-2; k++){
					if( dp[k][j-1].costo + costos[j][k] < min){
						min= dp[k][j-1].costo + costos[j][k];
					}
				}
				dp[j-1][j].costo = min;
				
			}
			else{
				dp[i][j].costo= dp[i][j-1].costo + costos[j][j-1];
			}
		}
	}
}
