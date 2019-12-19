#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int calculoResultado(vector<int> v, int & picos);



void casoDePrueba() {


	int numTemp = 0, picos = 0, valles = 0;

	cin >> numTemp;

	vector<int> v(numTemp);

	//Lectura de datos
	for (int i = 0; i < v.size(); i++){
		cin >> v[i];
	}


	//Calculo del resultado
	valles = calculoResultado(v, picos);


	//Escritura de resultado
	cout << picos << " " << valles << "\n";


} // casoDePrueba


int main() {


	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	
	}

	return 0;
}
		//Invariante:
		// 1 <= i < v.size() && 
		// valles = # k: 1 <= k < v.size() -1 : v[k - 1] > v[k] && v[k + 1] > v[k]
		// picos  = # j: 1 <= j < v.size() -1 : v[j - 1] < v[j] && v[j + 1] < v[j]

		if (v[i - 1] < v[i] && v[i + 1] < v[i]) picos++;

		else if (v[i - 1] > v[i] && v[i + 1] > v[i]) valles++;


		//La funci�n de cota es: v.size() - 1  - i
	}