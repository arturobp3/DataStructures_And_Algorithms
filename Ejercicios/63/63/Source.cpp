// NOMBRE Y APELLIDOS

#include <iostream>
#include "bintree_ext.h"
#include <fstream>
using namespace std;

bool resuelveCaso() {


	//Lee los datos
	bintree_ext<int> arbol = leerArbol_ext(-1);

	//Calcula el resultado

	bool binario = arbol.esBinario();


	if (binario){
		cout << "SI" << endl;
	}
	else{
		cout << "NO" << endl;
	}


	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;

	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}