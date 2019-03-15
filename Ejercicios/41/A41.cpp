#include <iostream>
#include <fstream>
#include <string>
#include "stack_eda.h"
using namespace std;

bool resuelveCaso() {

	// Leer caso de prueba
	string line;
	getline(cin, line);

	if (!std::cin) {
		return false;
	}
	else {
		char c;
		stack<char> pila;
		bool val = true;
		int i = 0;

		// Coste lineal, depende de la logintud del string de entrada
		while (i < line.size() && val) {
			c = line[i];

			if (c == '(' || c == '[' || c == '{') {
				pila.push(c);
			}
			else if (c == ')') {
				if (!pila.empty() && pila.top() == '(') {
					pila.pop();
				}
				else { val = false; }
			}
			else if (c == ']') {
				if (!pila.empty() && pila.top() == '[') {
					pila.pop();
				}
				else { val = false; }
			}
			else if (c == '}') {
				if (!pila.empty() && pila.top() == '{') {
					pila.pop();
				}
				else { val = false; }
			}
			++i;
		}

		if (val && pila.empty()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		return true;
	}
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