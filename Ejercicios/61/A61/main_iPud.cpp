
#include <iostream>
#include <fstream>
#include <vector>
#include "iPud.h"

using namespace std;

bool resuelveCaso() {

	string nombre, artista, orden;
	vector<string> recientes;

	int duracion, recent;

	cin >> orden;

	if (!cin)
		return false;

	iPud ipud;

	while (orden != "FIN") {
		try {

			if (orden == "addSong") {
				cin >> nombre >> artista >> duracion;

				ipud.addSong(nombre, artista, duracion);
			}

			else if (orden == "addToPlaylist") {
				cin >> nombre;
				ipud.addToPlaylist(nombre);
			}

			else if (orden == "current") {
				nombre = ipud.current();

			}

			else if (orden == "play") {
				nombre = ipud.play();

				if (nombre != ""){
					cout << "Sonando " << nombre << endl;
				}
				else{
					cout << "No hay canciones en la lista" << endl;
				}

			}

			else if (orden == "totalTime") {
				duracion = ipud.totalTime();
				cout << "Tiempo total " << duracion << endl;
			}

			else if (orden == "recent") {
				cin >> recent;
				recientes = ipud.recent(recent);

				if (recientes.size() > 0){
					cout << "Las " << recientes.size() << " mas recientes" << endl;
				
					for(string i : recientes){
						cout << "    ";
						cout << i << endl;
					}
				}
				else{
					cout << "No hay canciones recientes" << endl;
				}
			}

			else if (orden == "deleteSong") {
				cin >> nombre;
				ipud.deleteSong(nombre);
			}

		}

		catch (domain_error e) {
			cout << e.what() << '\n';
		}

		cin >> orden;
	}


	cout << "----\n";


	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
