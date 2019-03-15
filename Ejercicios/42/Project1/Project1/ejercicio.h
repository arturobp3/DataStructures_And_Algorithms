#include "list_eda.h"

template <class T>
class ejercicio {

public:

	ejercicio(){};

	void duplica(ejercicio<T> & lista){

		for (T & e : lista){
			Nodo * nuevo = new Nodo(e, nullptr, nullptr);
			lista.insert(nuevo);
		}
		
		

	}

	/*void mostrar(const ColaDuplica<T> & cola){

		/*for (T const& e : cola){
			cout << e->elem;
		}
	}*/

};