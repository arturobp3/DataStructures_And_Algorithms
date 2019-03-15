#include <iostream>
#include <fstream>

using namespace std;

void resolver(int numHijos, int alturaAct, const int &k, int &numBecarios);

bool resuelveCaso() {

	int k;
	cin >> k; // Numero minimo de jefes que tiene que tener un becario para considerarse precario

	if (!std::cin)
		return false;
	else {
		int numHijos = 0, alturaAct = 1;
		int numBecarios = 0;
		resolver(numHijos, alturaAct, k, numBecarios);

		cout << numBecarios << '\n';
	}

	return true;
}

void resolver(int numHijos, int alturaAct, const int &k, int &numBecarios) {

	cin >> numHijos;
	if (numHijos == 0) {
		if (alturaAct > k) { numBecarios++; }
		alturaAct = 1; 
	}
	else {
		for (int i = 0; i < numHijos; ++i) {

			alturaAct++;
			resolver(numHijos, alturaAct, k, numBecarios);
			alturaAct--;
		}
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