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

void Problema::mostrarResultado(ostream& os){
	//esto lo hago para q sea mas facil escribir la solucion, no agrega mucho
	int i= nodo_solucion; //pongo un i para q sea mas legible
	for(int j= cantTrabajos; j>=1; j--){
		if(dp[i][j].maquina==1){
			solucion.push_front(j);
		}
		i= dp[i][j].anterior;
	}
	
	//~ //mostrar matriz dp
	//~ for(int i=0; i<cantTrabajos; i++){
		//~ for(int j=1; j<=cantTrabajos; j++){
			//~ os<< dp[i][j].costo << " ";
		//~ }
		//~ os<< endl;
	//~ }
	
	// C k i_1 ... i_k
	os<< costo_final << " ";
	os<< solucion.size();
	
	while(!solucion.empty()){
		os<< " "<< solucion.front();
		solucion.pop_front();
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
	dp[0][1].anterior= -1;
	dp[0][1].maquina= 2;
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
				dp[i][j].anterior= kminimo;
				if(dp[kminimo][j-1].maquina==1){ //lo agrego a la maquina contraria a la q se encuentra j-1 (en la pos kminimo)
					dp[i][j].maquina= 2;
				}
				else{
					dp[i][j].maquina= 1;
				}
				
			}
			else{
				dp[i][j].costo= dp[i][j-1].costo + costos[j][j-1];
				dp[i][j].anterior= i;
				dp[i][j].maquina= dp[i][j-1].maquina; //lo agrego a la maquina donde esta j-1
			}
		}
	}
	//fin, falta encontrar el minimo de la ultima columna
	costo_final= 1e9;
	nodo_solucion;
	
	for(int i=0; i< cantTrabajos; i++){
		if(dp[i][cantTrabajos].costo < costo_final){ 
			costo_final= dp[i][cantTrabajos].costo;
			nodo_solucion= i;
		}
	}
}
