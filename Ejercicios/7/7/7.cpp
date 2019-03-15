#include <iostream>
#include <vector>
using namespace std;


int posMaximo(vector<int> array, int & maximo);
int sumSinMaximo(vector<int> array);
int sumaValores();

int sumaValores() {

	int n, suma;

	cin >> n;

	vector<int> array(n);

	for (int i = 0; i < array.size(); i++){
		cin >> array[i];
	}

	suma = sumSinMaximo(array);


	return suma;

} // casoDePrueba


int main() {

	unsigned int numCasos, i, suma;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		suma = sumaValores();
		cout << suma << "\n";
	}

	return 0;
}


int posMaximo(vector<int> array, int & maximo){
	int posMaximo;

	for (int i = 0; i < array.size(); i++){

		if (array[i] > maximo){
			maximo = array[i];
			posMaximo = i;
		}
	}

	return posMaximo;
}


//Precondición: { array != null }
int sumSinMaximo(vector<int> array){
//Postcondición: { suma = sumS( array[k..array.size()] ) && forall k:: 0 <= k <= array.size() : v[k] != maximo }


	int suma = 0;

	if (array.size() == 0) suma = 0;

	else{

		int maximo = -1;
		int posMaximo_ = posMaximo(array, maximo);
		int i = 0;

		/*Invariante: 0 <= i <= array.size() &&
					  posMaximo_ = exists k:: 0 <= k <= i : v[k] == maximo &&  
					  suma = sumS(array[j..i]) && forall j:: 0 <= j <= i : v[j] != maximo
		*/
		while(i < array.size()){

			if (i == posMaximo_ || array[i] == maximo) i++;
			else{
				suma = suma + array[i];
				i++;
			}

			//Función de cota: array.size() - i
		}
	}

	//El coste en el caso peor es del orden de n (lineal), siendo n el numero de elementos del array 

	return suma;
}