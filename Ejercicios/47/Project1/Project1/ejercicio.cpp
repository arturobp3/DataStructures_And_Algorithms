#include <iostream>
#include <fstream>
#include "bintree_ext.h"
using namespace std;



void resuelveCaso() {

	//Lee los datos
	bintree_ext<char> arbol = leerArbol_ext('.');

	size_t nodos, altura, hojas;

	//Calcula el resultado

	nodos = arbol.numNodos();
	hojas = arbol.numHojas();
	altura = arbol.altura();

	//Escribe el resultado

	cout << nodos << " " << hojas << " " << altura << endl;

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