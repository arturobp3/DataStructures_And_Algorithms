#include <iostream>
#include <fstream>
#include "ejercicio.h"
using namespace std;

bool resuelveCaso() {

	//Leer caso de prueba

	int num;

	cin >> num;

	if (!std::cin)
		return false;

	//Resolver problema
	else{

		if (num != 0){


			ejercicio<int> cola;


			while (num != 0){
				cola.push(num);
				cin >> num;
			}

			cola.invertir();
			cola.mostrar();
		}
		else cout << endl;
	
	}


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
