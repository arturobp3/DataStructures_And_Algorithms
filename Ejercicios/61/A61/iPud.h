#ifndef ipud_h
#define ipud_h

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

using nombre = string;
using artista = string;
using duracion = int;
using orden = int;
using info = pair<artista, duracion>;


class iPud : private unordered_map<nombre, info>{

private:

	queue<pair<nombre, duracion>> listaReproduccion;
	stack<nombre> cancionesReproducidas;

	bool buscar(vector<string> const & v, const string & nombre) {
		size_t i = 0;
		while (i < v.size() && v[i] != nombre) ++i;
		return i < v.size();
	}

	//Si encuentra el string en el stack, lo borra
	void borrarSiEncuentra(const string & s){
		stack<string> aux;

		string p = cancionesReproducidas.top();
		
		while (p != s && !cancionesReproducidas.empty()){

			aux.push(p);
			cancionesReproducidas.pop();

			if (!cancionesReproducidas.empty()){
				p = cancionesReproducidas.top();
			}
		}
		
		if (p == s){
			cancionesReproducidas.pop(); //Borra el elemento buscado
			
		}


		while (!aux.empty()){  //Recoloca todo

			cancionesReproducidas.push(aux.top());

			aux.pop();
		}
		
	}

	void borrarListaSiEncuentra(const string & s){
		queue<pair<nombre, duracion>> aux;

		pair<nombre,duracion> p = listaReproduccion.front();

		while (!listaReproduccion.empty()){

			if (p.first == s){
				listaReproduccion.pop(); //Borra el elemento buscado
			}
			else{
				aux.push(p);
				listaReproduccion.pop();
			}

			if (!listaReproduccion.empty()){
				p = listaReproduccion.front();
			}
		}

		while (!aux.empty()){  //Recoloca todo

			listaReproduccion.push(aux.front());

			aux.pop();
		}
	}

public:

	void addSong(const nombre& s, artista const & a, duracion const & d){
		if (!insert({ s, { a, d } }).second){
			throw domain_error("ERROR addSong");
		}
	}

	void addToPlaylist(nombre const & s){
		auto it = find(s);

		if (it == end()){
			throw domain_error("ERROR addToPlaylist");
		}
		else{
			listaReproduccion.push({ it->first, it->second.second });
		}
	}

	string current(){
		if (listaReproduccion.size() > 0){

			nombre current;

			current = listaReproduccion.front().first;

			return current;
		}
		else{
			throw domain_error("ERROR current");
		}
	}

	string play(){

		if (!listaReproduccion.empty()){

			string current = listaReproduccion.front().first;

			listaReproduccion.pop();

			cancionesReproducidas.push(current);

			return current;
		}
		else{
			throw domain_error("No hay canciones en la lista");
		}

	}

	int totalTime(){
		int time = 0;
		queue<pair<nombre, duracion>> aux = listaReproduccion;

		while (!aux.empty()){

			time += aux.front().second;
			aux.pop();
	
		}

		return time;
	}

	vector<nombre> recent(int N){
		vector<nombre> v;
		string aux;
		int pasadas = 0;
		stack<string> auxStack = cancionesReproducidas;


		if (cancionesReproducidas.size() < N){ //Numero de canciones reproducidas menor que el numero que se pide
											//Se cogen todas

			while (!auxStack.empty()){
				
				aux = auxStack.top();

				if (!buscar(v, aux)){
					v.push_back(aux);
				}

				auxStack.pop();

			}
		}
		else{ //Se cogen las ultimas pedidas

			while (pasadas < N){ 

				aux = auxStack.top();

				if (!buscar(v,aux)){
					v.push_back(aux);
					pasadas++;
				}

				auxStack.pop();
			}

		}

		return v;
	}

	void deleteSong(const nombre & s){
		auto it = find(s);


		if (!(it == end())){ //Si la ha encontrado
			this->erase(it->first);
		}
		
		if (!cancionesReproducidas.empty()){
			borrarSiEncuentra(s);
		}

		if (!listaReproduccion.empty()){
			borrarListaSiEncuentra(s);
		}

	}

};


#endif