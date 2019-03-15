
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "list_eda.h"
#include <list>

template <class T>
void mostrarLista(list<T> const& l, ostream & sout){
   auto it = l.cbegin();
   if (it != l.cend()) {
      sout << *it;
      ++it;
   }
   while (it != l.cend()){
      sout << ' ' << *it;
      ++it;
   }
   sout << '\n';
}


/* Dado la secuencia de enteros sec (no necesariamente ordenados) y un
 rango inf..sup, devuelve una lista ordenada con todos los
 números del rango que no estén en la secuencia.
 */
list<int> enRangoYNoEnSec(list<int> const& sec, int inf, int sup) {
   //Rellena aqui tu codigo

	list<int> rango;
	vector<bool> encontrados(sup + 1);

	list<int>::const_iterator it = sec.cbegin();

	while (it != sec.cend()){
		if (*it >= inf && *it <= sup) encontrados[*it] = true;

		++it;
	}

	int i = inf;
	while (i <= sup){
		if (encontrados[i]) i++;
		else{
			rango.push_back(i);
			i++;
		}
	}

	
	return rango;

   
   //Indica y justifica el coste

	/*
		El coste del algoritmo es lineal, O(n), siendo n el numero de elementos de la lista sec
		En el primer bucle se itera por la lista y en él se hacen:
			- Comparaciones: tiempo constante
			- Acceder al vector encontrados: tiempo constante
			- Asignación: tiempo constante
			- Incremento: tiempo constante
		Por lo que iterar por esta lista realizando una serie de operaciones constantes da un coste lineal

		En el segundo bucle comenzamos a iterar en i = inf y terminamos cuando i > sup
		Se accede por tanto a una parte del vector y por tanto el coste aqui sería O(n - c0) siendo n el tamaño del
		vector y c0 la diferencia entre sup e inf.
		Las operaciones que se realizan en este bucle son constantes y sucede lo mismo que en el bucle anterior,
		dando un coste lineal

		Por tanto tenemos un coste de O(2n) == O(n) (n = tamaño del vector)


	*/
}


bool resuelveCaso() {
   int n, inf, sup;
   list<int> sec;
   cin >> n;
   if (!cin) return false;
   while (n != -1){
      sec.push_back(n);
      cin >> n;
   }
   cin >> inf >> sup;
   auto res = enRangoYNoEnSec(sec, inf, sup);
   mostrarLista(res, cout);
   return true;
}

int main() {
   // Para la entrada por fichero.
#ifndef DOMJUDGE
   std::ifstream in("casos4.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
   
   while (resuelveCaso());
   
   // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
