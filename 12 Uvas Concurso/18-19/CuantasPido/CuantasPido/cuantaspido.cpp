#include <iostream>
using namespace std;



void casoDePrueba() {

	int compradas, a, b;


	cin >> compradas >> a >> b;

	int cajas = compradas / b;

	int malas = cajas * a;

	int res = b * cajas;

	if (res < compradas){ // Si cabe alguna más
		int resta = compradas - res;
		if (resta >= a){
			malas += a;
		}
		else if(resta < a){
			malas += resta;
		}
	}

	cout << malas << endl;
} 




int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}