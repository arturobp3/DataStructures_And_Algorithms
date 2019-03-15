//Nombre: Arturo Barbero Pérez

//VERSION SIN PODA


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int letrasDistintas(const string & solucion){

	vector<bool> letras(26);
	int cont = 0;


	//Coste lineal O(n), siendo n el tamaño de solución
	for (char i : solucion){
		letras[i - 'a'] = true;
	}


	//Coste lineal O(m) siendo m el tamaño de letras
	for (bool i : letras){
		if (i == true) cont++;
	}



	//Coste de la funcion: O(n + m)


	/*
		He pensado que aquí sería mejor el vector de 26 posiciones frente a un mapa desordenado (como hablamos antes)
		ya que para insertar un elemento en la tabla tienes que hacer un recorrido previo intentando localizar su clave,
		(que en el peor de los casos es del orden de n, siendo n el tamaño de la tabla) y pudiendo posteriormente que la insercción
		no se produzca porque la clave ya exista. Mientras que de esta manera, la instrucción de asignación se hace de manera constante.
		En el otro ejercicio puede que la entrada sea muy grande y se gaste mucha memoria
		pero aqui siempre habrá 26 letras independientemente del tamaño de "solucion"
	*/

	return cont;
}


void vueltaAtras(string & a, string & b, string & solucion, int &mayorDistintas, int nivel){
	int distintas;

	//En cada llamada a "vueltaAtras" hay dos posibles opciones para cada nivel.Una que contenga la letra de a
	//y otra que contenga la letra de b. Primero se prueba con una y luego con otra
	for (int i = 0; i < 2; i++){
		if (i % 2 != 0) solucion[nivel] = b[nivel];
		else solucion[nivel] = a[nivel];

		if (nivel == b.size() - 1){

			distintas = letrasDistintas(solucion); 

			if (distintas < mayorDistintas){
				mayorDistintas = distintas;
			}
		}
		else{
			vueltaAtras(a, b, solucion, mayorDistintas, ++nivel);
			nivel--;
		}
	}
}


bool resuelveCaso() {
    string a,b;
    cin >> a;
    if (!cin) return false;
    cin >> b;
    
    // Aqui el código implementado por el alumno

	int mayorDistintas = b.size();
	string solucion = a;

	vueltaAtras(a, b, solucion, mayorDistintas, 0);
	cout << mayorDistintas << endl;
    
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    ifstream in("casos2Final.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso())
        ;
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("pause");
#endif
    
    return 0;
}