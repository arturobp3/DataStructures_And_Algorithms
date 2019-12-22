#include <iostream>
using namespace std;


bool casoDePrueba() {
	
	char letra;
	int negros = 0, grises = 0;

	cin >> letra;

	if (letra == '.'){
		return false;
	}

	while (letra != '.'){

		if (letra == 'G'){
			grises++;
		}
		else{
			negros++;
		}

		cin >> letra;
	}


	if (negros % 2 == 0 && grises % 2 == 0){
		cout << "EMPAREJADOS" << endl;
	}
	else if (negros % 2 != 0 && grises % 2 != 0){
		cout << "PAREJA MIXTA" << endl;
	}
	else if(negros % 2 != 0){
		cout << "NEGRO SOLITARIO" << endl;
 	}
	else {
		cout << "GRIS SOLITARIO" << endl;
	}

	return true;
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}