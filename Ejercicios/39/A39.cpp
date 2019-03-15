#include <iostream>
#include "deque_eda.h"

using namespace std;

int resolver(deque<int> cola, int n, int m);

deque<int> salvados(deque<int> dcola, int m);

bool casoDePrueba() {
	// Leer caso de prueba
	int n, m;
	cin >> n;
	cin >> m;

	if (n == 0 && m == 0)
		return false;
	else {
		deque<int> cola;
		cout << resolver(cola, n, m) << '\n';
		return true;
	}
} // casoDePrueba

int resolver(deque<int> cola, int n, int m) {
	for (int i = 1; i <= n; ++i) {
		cola.push_back(i);
	}
	
	deque<int> solucion;
	if (m == 1) {
		solucion.push_back(cola.back());
	}
	else {
		solucion = salvados(cola, m);
		while (solucion.size() >= m) {
			solucion = salvados(solucion, m);
		}
	}

	
	return solucion.back();
}

deque<int> salvados(deque<int> dcola, int m) {
	deque<int> noSalvados;
	int i = 0; // Contador de posiciones que salto (no las salvo)

	while (dcola.size() >= m) {
		while (i < m - 1) // Coste lineal: se realizan las asignaciones siempre m - 1 veces :: O(m-1)
		{
			noSalvados.push_back(dcola.front()); // No se salva, lo guardamos
			dcola.pop_front(); // Lo borramos de la dcola original
			++i;
		}
		dcola.pop_front(); // Se salva, lo borramos sin mas
		i = 0;
	}

	while (dcola.size() > 0) {
		noSalvados.push_front(dcola.back());
		dcola.pop_back();
	}

	return noSalvados;
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}