#include <iostream>
#include "deque_eda.h"

using namespace std;

void resolver(deque<int> cola, int n);

void afortunados(deque<int> &dcola, deque<int> &sol, int m);

void mostrar(deque<int> &cola, const int &tam);

bool casoDePrueba() {
	// Leer caso de prueba
	int n;
	cin >> n;

	if (n == 0)
		return false;
	else {
		deque<int> cola;
		cout << n << ": ";
		resolver(cola, n);
		return true;
	}
} // casoDePrueba

void resolver(deque<int> cola, int n) {
	// Creamos la cola con valores de 1 a n
	for (int i = 1; i <= n; ++i) {
		cola.push_back(i);
	}
	// Calculamos los numeros afortunados y los mostramos
	int m = 2;
	deque<int> sol;
	// Coste n*m, dependiendo del orden en el que esté m expresado, será exponencial o lineal
	afortunados(cola, sol, m);

	const int tam = sol.size();
	mostrar(sol, tam);
}

void afortunados(deque<int> &dcola, deque<int> &sol, int m) {
	int i = 0;
	int n = dcola.size();
		
	while (i < n && !dcola.empty()) {
		if (i % m == 0) {
			dcola.pop_front(); 
		}
		else {
			sol.push_back(dcola.front());
			dcola.pop_front();
		}
		++i;
	}
	++m;
	if (sol.size() >= m) {
		afortunados(sol, dcola, m);
		sol = dcola;
	}
}

void mostrar(deque<int> &cola, const int &tam) {
	for (int i = 0; i < tam; ++i) {
		cout << cola.back() << " ";
		cola.pop_back();
	}
	cout << '\n';
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}