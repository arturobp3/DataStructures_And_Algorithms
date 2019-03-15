#include "treemap_eda.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;


map<string, string> leerDiccionario(map<string, int> & contadores);
string a_mayusculas(const string & s);
void mostrarResultado(map<string, int> & contadores);

bool casoDePrueba() {
	map<string, int> contadores;
	map<string, string> listas = leerDiccionario(contadores);
	

	contadores.print();

	//mostrarResultado(contadores);


	return true;
}
 // casoDePrueba
int main() {
	while (casoDePrueba()) {
	}

	return 0;
}

void mostrarResultado(map<string, int> & contadores){

	map<string, int>::const_iterator it = contadores.cbegin(); //Iterador del primer diccionario
	int mostrados = 0;
	int maximo = -1;
	string claveDelMaximo = "";
	int sizeContadores = contadores.size();

	while (mostrados < sizeContadores){

		while (it != contadores.cend()){

			if (it->valor > maximo){
				maximo = it->valor;
				claveDelMaximo = it->clave;
			}
			else if (it->valor == maximo){
				if (it->clave < claveDelMaximo){

					claveDelMaximo = it->clave;
				}
			}

			++it;
		}

		cout << claveDelMaximo << " " << maximo << endl;

		contadores.erase(claveDelMaximo);
		it = contadores.cbegin();
		maximo = -1;
		mostrados++;
	}


	cout << "***" << endl;
}

map<string, string> leerDiccionario(map<string, int> & contadores){

	using cv = map<string, string>::clave_valor;
	using cn = map<string, int>::clave_valor;
	map<string, string> listas;
	int vecesAparecidas;
	
	string valor, clave;

	
	getline(cin, valor); //Obtiene el primer deporte
	if (valor != "_FIN_"){
		cn contadorNuevo(valor, 0);
		contadores.insert(contadorNuevo); //Crea un nuevo par (Deporte, lista de alumnos apuntados)
	}

	while (valor != "_FIN_"){

		getline(cin, clave);
		string aux = a_mayusculas(clave);

		if (clave != aux && listas.count(clave) == 0){ //Si la clave que se ha leido es distinto de mayusculas (es decir, no es otro valor)
													// y ademas no esta en el diccionario
			cv c(clave, valor);
			listas.insert(c);		//Cuando se inserta un nuevo alumno
									//Borramos el par creado antes, y añadimos un nuevo par en contadores con el contador actualizado.

			vecesAparecidas = contadores.at(valor);
			contadores.erase(valor);
			contadores.insert(cn(valor, vecesAparecidas + 1));

		}
		else{
			if (clave == aux){  //Si es otro valor
				valor = clave;

				if (valor != "_FIN_"){
					cn contadorNuevo(valor, 0);
					contadores.insert(contadorNuevo); //Crea un nuevo par (Deporte, lista de alumnos apuntados)
				}

			}
			else if (listas.count(clave) == 1){ //Si esta hay dos opciones. Que su deporte sea el mismo, en ese caso solo se cuenta una vez
												//O que no sea el mismo y se elimina del diccionario
				if (valor != listas.at(clave)){

					string valorDeAntes = listas.at(clave); //Consigue el valor de antes

					listas.erase(clave); //Borra la clave

					vecesAparecidas = contadores.at(valorDeAntes); //Resta en contadores el contador del valor de antes
					contadores.erase(valorDeAntes);
					contadores.insert(cn(valorDeAntes, vecesAparecidas - 1));


					//Esto supone que no aparezca en ningun valor esta clave
				}
				else{
				
					//contar una vez
				}
			}
		}
	}

	return listas;
}


string a_mayusculas(const string & s) {
	string devolver = "";

	for (int i = 0; i < s.length(); i++) {
		devolver += toupper(s[i]);
	}

	return devolver;
}
	

