#include <iostream>
#include <math.h>
using namespace std;

const int N = 10000;


void criogenizacion(long long v[], int n, long long &mayor, long long &fMayor, long long &menor, long long &fMenor);



void casoDePrueba() {


	long long v[N];
	int i = 0;
	long long datoLeido;

	// Lectura de datos

	cin >> datoLeido; //evita guardar en el array el 0 del final

	while (datoLeido != 0){
		v[i] = datoLeido;
		i++;
		cin >> datoLeido;
	}

	// Proceso de datos
	long long mayor = v[0], frecuenciaMayor = 1;
	long long menor = v[0], frecuenciaMenor = 1;


	criogenizacion(v, i, mayor, frecuenciaMayor, menor, frecuenciaMenor);


	// Salida de datos

	cout << menor << " " << frecuenciaMenor << " " << mayor << " " << frecuenciaMayor << "\n";


} // casoDePrueba


// Precondicion: { 0 <= n <= v.Length && fMayor = 1 && fMenor = 1 && mayor = v[0] && menor = v[0] }

void criogenizacion(long long v[], int n, long long &mayor, long long &fMayor, long long &menor, long long &fMenor){

// Postcondicion: { mayor = max i : 0 <= i < n : v[i] }
// Postcondicion: { fMayor = #j : 1 <= j < n : v[j] == mayor }
// Postcondicion: { menor = min i : 0 <= i < n : v[i] }
// Postcondicion: { fMenor = #j : 1 <= j < n : v[j] == menor }


	long long minimoAnterior = v[0], maximoAnterior = v[0];

	//Invariante:
	// 1 <= i <= n &&
	// mayor = max u : 0 <= u < i : v[u] && 
	// fMayor = #u : 1 <= u < i : v[u] == mayor && 
	//  menor = min w : 0 <= w < i : v[w] && 
	// fMenor = #w : 1 <= w < i : v[w] == menor 

	for (int i = 1; i < n; i++){

		if (v[i] == mayor && v[i] == menor){
			fMayor++;
			fMenor++;
		}
		else if (v[i] == mayor) fMayor++;
		else if (v[i] == menor) fMenor++;

		else if (v[i] < menor && v[i] != minimoAnterior){
			minimoAnterior = menor;
			menor = v[i];
			fMenor = 1;
		}
		else if (v[i] > mayor && v[i] != maximoAnterior){
			maximoAnterior = mayor;
			mayor = v[i];
			fMayor = 1;
		}
	}
	


}

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}