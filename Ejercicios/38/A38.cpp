#include <iostream>
#include "stack_eda.h"

using namespace std;

bool casoDePrueba() {
	
	int n;
	cin >> n;
	if (n == -1)
		return false;
	else {
		stack<int> pila;
		if (n == 0) {
			cout << "0 = 0" << '\n';
		}
		else {
			while (n > 0) {
				int m = n % 10;
				pila.push(m);
				n = n / 10;
			}
			int suma = 0;
			while (!pila.empty()) {
				int cifra = pila.top();
				suma += cifra;
				if (pila.size() == 1) {
					cout << cifra << " = " << suma << '\n';
				}
				else { cout << cifra << " + "; }

				pila.pop();
			}
		}
		
		
		return true;
	}
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}