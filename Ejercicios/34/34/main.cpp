#include <iostream>
#include "Pelicula.h"
#include <vector>
#include <algorithm>
using namespace std;

void mostrarLista(vector<Pelicula> & lista);

bool casoDePrueba() {
	int numPeliculas;

	cin >> numPeliculas;

	if (numPeliculas == 0)
		return false;
	else {
		int i = 0;
		Horas inicio, duracion;
		string nombre;
		vector<Pelicula> lista;
		
		while (i < numPeliculas){
			
			inicio.read();
			duracion.read();
			getline(cin, nombre);

			Pelicula nueva(inicio, duracion, nombre);

			lista.push_back(nueva);
			
			i++;
		}

		mostrarLista(lista);

		return true;
	}
} // casoDePrueba


void mostrarLista(vector<Pelicula> & lista) {
	sort(lista.begin(), lista.end());

	for (int i = 0; i < lista.size(); i++){
		lista.at(i).getFinalizacion().print();
		cout << " " << lista.at(i).getNombre() << endl;
	}

	cout << "---" << endl;
}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}