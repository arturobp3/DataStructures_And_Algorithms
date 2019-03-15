
#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"  // con lista enlazada doble con fantasma

class EngordarLista : public deque<int> {
   using Nodo = deque<int>::Nodo;
public:
   void print(std::ostream& o = std::cout) const {
      if (!this->empty()) {// la lista no está vacía
         Nodo * aux = this->fantasma->sig;
         o << aux->elem;
         aux = aux->sig;
         while (aux != this->fantasma) {
            o << ' ' << aux->elem;
            aux = aux->sig;
         }
      }
   }
   
   // introduce los elementos de other (una lista enlazada)
   // en la lista representada por this alternativamente al principio y al final
   void engordar(EngordarLista & other) {
      //Rellena aqui tu codigo

	   int i = 0;

	   while (i < other.size()){

		   if (i % 2 == 0){
			   //Nos guardamos los datos que habia anteriormente para luego asignarlos
			   Nodo * sigAnteriorThis = this->fantasma->sig; 
			   Nodo * sigAnteriorOther = other.fantasma->sig->sig;

			   this->fantasma->sig->ant = other.fantasma->sig; //El anterior pasa a ser el primer elemento de other
			   this->fantasma->sig = other.fantasma->sig;	   //El fantasma apunta al que acabas de poner
			   this->fantasma->sig->sig = sigAnteriorThis;	   //Sig del elemento que acabas de poner apunta al que habia antes

			   other.fantasma->sig = sigAnteriorOther;			//Actualizamos el fantasma de other al siguiente de la lista
			   other.fantasma->sig->ant = other.fantasma;		//el ant del siguiente de la lista es el fantasma
		   }
		   else{
			   Nodo * antAnteriorThis = this->fantasma->ant;
			   Nodo * sigAnteriorOther = other.fantasma->sig->sig;

			   this->fantasma->ant->sig = other.fantasma->sig;	//Asignamos el siguiente elemento de other al final
			   this->fantasma->ant = other.fantasma->sig;		//El fantasma apunta al que acabas de poner
			   this->fantasma->ant->ant = antAnteriorThis;		//Ant del elemento que acabas de poner apunta al que habia antes

			   other.fantasma->sig = sigAnteriorOther;			//Actualizamos el fantasma de other al siguiente de la lista
			   other.fantasma->sig->ant = other.fantasma;		//el ant del siguiente de la lista other es el fantasma

		   }

		   i++;
		   this->nelems++;

		   //AQUI me faltó ir disminuyendo el numero de elementos de others
	   }


		//AQUÍ me faltó enlazar: this->fantasma->sig->ant = this->fantasma


		this->fantasma->ant->sig = this->fantasma;	// al final de todo el ultimo tiene que apuntar al fantasma




      //Indica y justifica el coste
		/*
			El coste del algoritmo es lineal, O(n) siendo n el tamaño de other.
			Con cada vuelta al bucle se mira si la iteración en la que estamos es par o no.
			Si es par toca añadir el elemento por el principio, mientras que si es impar toca
			añadirlo por el final
			Con cada vuelta las operaciones se realizan en tiempo constante ya que se basan
			en redirigir punteros.

		*/

   }
   
};

inline std::ostream& operator<<(std::ostream & o, EngordarLista const& a) {
   a.print(o);
   return o;
}

EngordarLista leerLista() {
   EngordarLista lista;
   int n;
   std::cin >> n;
   while (n != 0) {
      lista.push_back(n);
      std::cin >> n;
   }
   return lista;
}

bool resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   lista1.engordar(lista2);
   std::cout << lista1 << '\n';
   return true;
}

int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   std::ifstream in("casos3.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   while (casos--) {
      resuelveCaso();
   }
   
   // restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}

