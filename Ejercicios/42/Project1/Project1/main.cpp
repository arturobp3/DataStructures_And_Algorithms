#include <iostream>
#include <fstream>
#include "list_eda.h"
using namespace std;

bool resuelveCaso() {

	//Leer caso de prueba

	int num;

	cin >> num;

	if (!std::cin)
		return false;

	//Resolver problema
	else{

		list<int> lista;

		while (num != 0){
			lista.push_back(num);
			cin >> num;
		}

		list<int>::iterator it = lista.begin();

		for (int & e : lista){
			lista.insert(it, e);
			it++;
		}

		for (const int & e : lista){
			cout << e << " ";
		}
	}

	cout << endl;

	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}