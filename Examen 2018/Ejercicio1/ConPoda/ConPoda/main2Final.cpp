
//VERSION CON PODA




#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
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
		He pensado que aquí sería mejor el vector de 26 posiciones frente a un mapa desordenado ya que para insertar un elemento
		en la tabla tienes que hacer un recorrido previo intentando localizar su clave,(que en el peor de los casos es del orden de n,
		siendo n el tamaño de la tabla) y pudiendo posteriormente que la insercciónno se produzca porque la clave ya exista.
		Mientras que de esta manera, la instrucción de asignación se hace de manera constante.
		En el otro ejercicio puede que la entrada sea muy grande y se gaste mucha memoria
		pero aqui siempre habrá 26 letras independientemente del tamaño de "solucion"
	*/

	return cont;
}

bool esSolucion(int nivel, const string & b){
	return (nivel == b.size() - 1);
}


/*La idea que he tenido para implementar la poda es que el string "solucion" contendrá menos letras cuanto 
más letras contenga con mayor aparición entre los dos strings juntos. (a y b).
Basándonos en eso, si estamos en una iteración par (en este caso el 0) se habrá asignado: solucion[nivel] = a[nivel]
Por tanto, si esa aparición es mayor o igual que la de b[nivel], la asignación se consideraría válida puesto que hay más 
probabilidades de que la solución final contenga la letra a[nivel]
Ocurriría lo mismo para el caso contrario en el que la iteración es impar (en este caso el 1) y se asigna: solucion[nivel] = b[nivel]
*/
bool esValida(int nivel, unordered_map<char, int> & m, int i, const string & a, const string & b){

	return (i % 2 != 0 && m[b[nivel]] >= m[a[nivel]]) || (i % 2 == 0 && m[a[nivel]] >= m[b[nivel]]);

	//Que la iteración sea impar y la aparición de la letra b[nivel] sea mayor o igual que la aparicion de la letra a[nivel]
	//Que la iteración sea par y la aparición de la letra a[nivel] sea mayor igual que la aparición de la letra b[nivel]
}


void vueltaAtras(string & a, string & b, string & solucion, int &mayorDistintas, int nivel, unordered_map<char, int> & m){
	int distintas;

	for (int i = 0; i < 2; i++){

		if (i % 2 != 0) solucion[nivel] = b[nivel];
		else solucion[nivel] = a[nivel];

		if (esValida(nivel, m, i, a, b)){
			if (esSolucion(nivel, b)){

				distintas = letrasDistintas(solucion);

				if (distintas < mayorDistintas){
					mayorDistintas = distintas;
				}
			}
			else{
				vueltaAtras(a, b, solucion, mayorDistintas, ++nivel, m);
				nivel--;
			}
		}
	}
}

void prepararInformacion(const string & a1, const string & b1, unordered_map<char, int> & a){

	//Cada vez que aparece una letra en el string a1, apunta su aparición
	for (char i : a1){
		a[i] += 1;
	}

	//Cada vez que aparece una letra en el string b1, apunta su aparición
	for (char i : b1){
		a[i] += 1;
	}
}


bool resuelveCaso() {
    string a,b;
    cin >> a;
    if (!cin) return false;
    cin >> b;
    

	int mayorDistintas = b.size();
	string solucion = a;

	unordered_map<char, int> apariciones; //Cantidad de veces que aparece una letra entre los dos strings


	prepararInformacion(a, b, apariciones);


	vueltaAtras(a, b, solucion, mayorDistintas, 0, apariciones);
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