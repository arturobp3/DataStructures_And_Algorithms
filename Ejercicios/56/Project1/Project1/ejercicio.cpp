#include <iostream>
#include "treemap_eda.h"
#include <string>
#include <sstream>
#include <vector>
using namespace std;

map<string, int> leerDiccionario();
void mostrarResultado(const vector<string> &vec);

void casoDePrueba() {
	// TU CÓDIGO AQUÍ

	string linea;
	bool salir = false;

	map<string, int> dicc = leerDiccionario();
	map<string, int> dicc2 = leerDiccionario();

	map<string, int>::const_iterator it = dicc.cbegin(); //Iterador del primer diccionario
	map<string, int>::const_iterator it2 = dicc2.cbegin();


	vector<string> aniadidos;
	vector<string> eliminados;
	vector<string> modificados;

	if (dicc.size() > 0 && dicc2.size() > 0){ //Si los dos son diccionarios vacios

		while(!salir){

			if (it2 == dicc2.cend()){			//Si it2 ha terminado la iteracion el resto estan eliminados
				eliminados.push_back(it->clave);
				++it;
			}
			else if (it == dicc.cend()){				//Si it 1 ha terminado la iteracion el resto estan añadidos
				aniadidos.push_back(it2->clave);
				++it2;
			}

			
			else if (it->clave == it2->clave){		//Si las claves son iguales, comparamos los valores y si son distintos significa que se ha modificado

				if (it->valor != it2->valor){
					modificados.push_back(it->clave);
				}
				++it2;
				++it;
			}

			else if (it->clave < it2->clave){         //Si la clave del primero es menor que la del segundo, significa que esta ya no aparece y se ha eliminado
				eliminados.push_back(it->clave);
				++it;
			}

			else if (it->clave > it2->clave){		//Si la clave del primero es mayor significa que se ha añadido una nueva en el segundo diccionario
				aniadidos.push_back(it2->clave);
				++it2;

			}


			if (it == dicc.cend() && it2 == dicc2.cend()){ //Si han terminado los dos, termina el bucle
				salir = true;
			}

		}
	}
	else{
		if (dicc.size() == 0){					//Si el dicc1 esta vacio significa que el resto estan añadidos
			for (it2; it2 != dicc2.cend();){
				aniadidos.push_back(it2->clave);
				++it2;
			}
		}
		else if (dicc2.size() == 0){			//Si el dicc2 esta vacio significa que todos los del dicc1 estan eliminados
			for (it; it != dicc.cend();){
				eliminados.push_back(it->clave);
				++it;
			}
		}
	}


	//Visualizacion de resultados

	if (aniadidos.size() == 0 && eliminados.size() == 0 && modificados.size() == 0){
		cout << "Sin cambios" << endl;
	}
	else{

		if (aniadidos.size() != 0){
			cout << "+ "; mostrarResultado(aniadidos);
		}
		if (eliminados.size() != 0){
			cout << "- "; mostrarResultado(eliminados);
		}
		if (modificados.size() != 0){
			cout << "* "; mostrarResultado(modificados);
		}
	}

	cout << "----" << endl;
	


	
}

void mostrarResultado(const vector<string> &vec){

	for (int i = 0; i < vec.size(); i++){
		cout << vec.at(i) << " ";
	}

	cout << endl;

}


map<string, int> leerDiccionario(){

	using cv = map<string, int>::clave_valor;
	map<string, int> dicc;

	string linea;
	string clave;
	int valor;

	getline(cin, linea);

	stringstream ss(linea);

	while (ss >> clave >> valor) {

		cv c(clave, valor);

		dicc.insert(c);
	}

	return dicc;

}


int main() {

	unsigned int numCasos, i;

	cin >> numCasos;
	cin.ignore();

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}