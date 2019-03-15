#include <iostream>
#include <fstream>
#include "hashmap_eda.h"
#include <string>
#include <sstream>

using namespace std;

void resuelveCaso() {

	// Lee los datos
	unordered_map<int, int> map;
	int numCaps;
	cin >> numCaps; // Leemos el numero de capitulos

	using cv = unordered_map<int,int>::clave_valor;
	int num, i = 0, cont = 0, mejorLongitud = 1;
	cin >> num;
	while (i < numCaps) {
		if (map.insert(num)) {
			++cont;
			if (cont > mejorLongitud) {
				mejorLongitud = cont;
			}
		}
		else {
			cont = 1;
		}
		++i;
		cin >> num;
	}
	cout << mejorLongitud << '\n';

	// Calcula el resultado

	int p; // Posicion de comienzo del segmento que cumple la propiedad


	// Escribe el resultado
}

int main() {
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}