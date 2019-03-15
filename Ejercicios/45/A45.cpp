#include <iostream>

using namespace std;

void resolver(int numHijos, int alturaAct, int &alturaMejor);

void casoDePrueba() {
	
	int numHijos = 0, alturaAct = 1, alturaMejor = 1; // Si es un arbol hoja, tendra altura = 1
	resolver(numHijos, alturaAct, alturaMejor);
	cout << alturaMejor << '\n';
}

void resolver(int numHijos, int alturaAct, int &alturaMejor) {

	cin >> numHijos;
	if (numHijos == 0) { alturaAct = 1; }
	else {
		for (int i = 0; i < numHijos; ++i) {

			alturaAct++;
			if (alturaAct > alturaMejor) {
				alturaMejor = alturaAct;
			}
			resolver(numHijos, alturaAct, alturaMejor);
			alturaAct--;
		}
	}
}

int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}
	system("pause");
	return 0;
}