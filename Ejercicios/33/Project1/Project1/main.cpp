#include <iostream>
#include "horas.h"
#include <vector>
#include <string>
using namespace std;

inline istream & operator>>(istream & in, Horas & hrs);
inline ostream & operator<<(ostream & out, Horas const& hrs);
bool consultarHora(vector<Horas> const& hrs, const Horas & consultado, int & pos);

bool casoDePrueba() {
	try{
		int numTrenes, numConsultas, i = 0;
		cin >> numTrenes >> numConsultas;

		vector<Horas> trenes(numTrenes);


		if (numTrenes == 0 && numConsultas == 0) return false;
		else {

			//Lectura de las horas de los trenes
			do{
				cin >> trenes[i];
				i++;
			} while (i < numTrenes);

			//Lectura de las consultas con sus respectivas salidas
			for (int i = 0; i < numConsultas; i++){
				int pos;
				Horas horaNueva;

				cin >> horaNueva;

				if (consultarHora(trenes, horaNueva, pos)){
					trenes[pos].print(cout);
					cout << endl;
				}
				else{
					cout << "NO\n";
				}
			}
	
			cout << "---\n";
			return true;
		}

	}catch (exception & e){
		cout << "ERROR\n" << endl;
	}

	return true;
}


inline istream & operator>>(istream & in, Horas & hrs) {
	hrs.read(in);
	return in;
}

inline ostream & operator<<(ostream & out, Horas const& hrs) {
	hrs.print(out);
	return out;
}

bool consultarHora(vector<Horas> const& hrs, const Horas & consultado, int & pos){

	int ini = 0, fin = hrs.size(), mitad;
	bool encontrado = false;
	Horas diferenciaHoras1;
	Horas diferenciaHoras2;
	
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; 

		if (mitad > 0){
			diferenciaHoras1 = hrs[mitad] - consultado;
			diferenciaHoras2 = hrs[mitad - 1] - consultado;

			if (diferenciaHoras1 < diferenciaHoras2){
				ini = mitad + 1;
			}
			else if (diferenciaHoras2 < diferenciaHoras1){
				fin = mitad - 1;
			}
			else encontrado = true;
		}
		else encontrado = true;
	}
	if (encontrado) pos = mitad; 
	else pos = ini; 

	return encontrado;

}

int main() {
	while (casoDePrueba()) {
	}

	return 0;
}

