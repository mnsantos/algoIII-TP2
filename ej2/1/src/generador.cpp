#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int main()
{	
	int nodosLim;
	cin>>nodosLim;
	for (int i=5; i<nodosLim; i++){ //para cada instancia
		int r;
		r=(i*(i-1))/2;
		cout<<i<<" "<<r<<endl;
		for (int j=1;j<=i;++j){
			for (int h=j+1;h<=i;++h){
				cout<<j<<" "<<h<<" "<<rand()%10<<endl;
			}
		}
	}
	cout <<"0";
	return 0;
}
