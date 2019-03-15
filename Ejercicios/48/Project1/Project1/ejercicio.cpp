#include <iostream>
#include <fstream>
#include "bintree_ext.h"
using namespace std;



void resuelveCaso() {

	//Lee los datos
	bintree_ext<int> arbol = leerArbol_ext(-1);



	//Calcula el resultado

	vector<int> frontera = arbol.calculaFronteraPostOrden();

	//Escribe el resultado

	for (int i = 0; i < frontera.size(); i++){
		cout << frontera[i] << " ";
	}

	cout << endl;

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