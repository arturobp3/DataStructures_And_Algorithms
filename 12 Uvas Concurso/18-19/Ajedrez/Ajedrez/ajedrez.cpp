#include <iostream>
using namespace std;
bool casoDePrueba() {

	int fila, columna;

	cin >> fila >> columna;
	if (fila == 0 && columna == 0)
		return false;
	else {
	
		char arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

		cout << arr[8 - fila] << columna << endl;

		return true;
	}

}



int main() {
	while (casoDePrueba()) {
	}

	return 0;
}