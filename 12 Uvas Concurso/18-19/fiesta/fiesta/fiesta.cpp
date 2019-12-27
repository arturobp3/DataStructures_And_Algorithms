#include <iostream>
#include <string>
using namespace std;



void casoDePrueba() {
	
	string varSoy, nombre;

	cin >> varSoy >> nombre;


	cout << "Hola, " << nombre << "." << endl;

} 


int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}