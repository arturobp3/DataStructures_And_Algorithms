#include <iostream>
#include <vector>
using namespace std;

bool implementacion(vector <char> v, int i, int & fugado);



void casoDePrueba() {
	// TU CÓDIGO AQUÍ
	bool primero = false;
	bool ultimo = false;
	char x1, x2;
	int tam, fugado;

	cin >> x1 >> x2;

	tam = int(x2) - int(x1);
	
	vector<char> v(tam);

	for (int i = 0; i < tam; i++){
		cin >> v[i];
	}

	if (int(v[0]) == int(x1)) primero = true;
	if (int(v[v.size() - 1]) == int(x2)) ultimo = true;

	bool resultado = implementacion(v, 0, fugado);

	if (resultado == false && primero == true) fugado = int(x2);
	else if (resultado == false && ultimo == true) fugado = int(x1);


	cout << char(fugado) << "\n";


} // casoDePrueba


int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}
	return 0;
}


//Precondicion: v != null && i = 0
bool implementacion(vector <char> v, int i, int & fugado){
//Postcondición: encontrado = { exists k:: 0 <= k < v.size() : v[i] == v[k] - 1 && v[i + 1] == v[k] + 1 : int(k) }
//El coste del algoritmo es lineal en el numero de elementos de v, ya que va haciendo una comprobación de un elemento con el siguiente
//hasta llegar al final.

	bool encontrado = false;

	if (i < v.size() - 1){
		if (int(v[i]) == int(v[i + 1] - 1)){
			encontrado = implementacion(v, i + 1, fugado);
		}
		else{
			encontrado = true;
			fugado = int(v[i]) + 1;
		}
	}

	return encontrado;
}
