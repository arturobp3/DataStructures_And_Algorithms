#include <iostream>
#include "horas.h"
using namespace std;


void casoDePrueba() {
	
	Horas inicio, fin, hora;
	int campanadas, buscada, segundos;

	inicio.read();
	fin.read();
	cin >> campanadas >> buscada;

	int diferencia = fin - inicio;
	int segsPorCampanada = diferencia / (campanadas - 1);
	int segsBuscada = segsPorCampanada * (buscada-1);

	Horas horaComienzo = inicio.suma(segsBuscada);

	horaComienzo.print();
	cout << endl;

} 


int main() {

	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}