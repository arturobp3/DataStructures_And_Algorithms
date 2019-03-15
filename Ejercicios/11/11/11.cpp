#include <iostream>
#include <vector>
using namespace std;

bool implementacion(vector<int> v, int ini, int fin);

bool casoDePrueba() {

	int leido, i = 0;
	vector<int> v;
	
	cin >> leido;

	if (leido == 0) return false;

	while (leido != 0){
		v.push_back(leido);
		i++;

		cin >> leido;
	}

	bool resultado = implementacion(v, 0, v.size() - 1);

	if (resultado) cout << "SI\n";
	else cout << "NO\n";

	return true;
	
} // casoDePrueba


int main() {
	while (casoDePrueba()) {
	}

	return 0;
}


void calcularMaxMins(vector<int> v, int ini, int fin, int & max_i, int & min_i, int & max_j, int & min_j){
	int mitad = (ini + fin) / 2;
	min_i = v[ini];
	max_i = v[mitad];
	min_j = v[mitad+1];
	max_j = v[fin];
}

bool implementacion(vector<int> v, int ini, int fin){
	bool mitadesOrdenadas = false;
	int max_i, min_i, max_j, min_j;

	if (ini < fin){
		calcularMaxMins(v, ini, fin, max_i, min_i, max_j, min_j);

		if (max_j == max_i && min_i == min_j) return true;

		if (max_j >= max_i && min_i <= min_j){
			int mitad = (ini + fin) / 2;

			mitadesOrdenadas = true;
			mitadesOrdenadas = implementacion(v, 0, mitad);
			mitadesOrdenadas = implementacion(v, mitad + 1, v.size() - 1);
		}

		else return false;

	}

	else return true;
}