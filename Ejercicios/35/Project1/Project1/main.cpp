#include "Polinomio.h"
#include <iostream>
#include <fstream>
using namespace std;

bool resuelveCaso() {

	Polinomio p;
	int coeficiente;
	int exponente;
	int numCasos;

	//Resolver problema

	cin >> coeficiente >> exponente;

	if (!std::cin || (coeficiente == 0 && exponente == 0)) return false;
	else{

		do{

			Monomio<int, int> m(coeficiente, exponente); //Crea un mononomio con los nuevos valores leidos
			p.inserta(m);

			cin >> coeficiente >> exponente;

		} while (!(coeficiente == 0 && exponente == 0));

	}


	//Lectura de casos a evaluar
	cin >> numCasos;
	vector<int> evaluar(numCasos);

	for (int i = 0; i < numCasos; i++){
		cin >> evaluar[i];
	}

	for (int i = 0; i < numCasos; i++) {
		int resultado = p.evaluarPolinomio(evaluar[i]);
		cout << resultado << " ";
	}

	cout << endl;
	
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