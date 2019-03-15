#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class ejercicio : public queue<T>{
	using Nodo = typename queue<T>::Nodo;
public:

	void invertir(){

		Nodo* anterior = nullptr;
		Nodo* primeroAux = this->prim;
		Nodo* segundoAux = this->prim->sig;


		while (segundoAux != nullptr){
			primeroAux->sig = anterior;
			anterior = primeroAux;
			primeroAux = segundoAux;
			segundoAux = segundoAux->sig;
		}
	
		primeroAux->sig = anterior;

		Nodo * intercambio = this->prim;
		this->prim = this->ult;
		this->ult = intercambio;

	}


	void mostrar(){
		Nodo * aux = this->prim;

		for (int i = 0; i < this->nelems; i++){
			cout << aux->elem << " ";
			aux = aux->sig;
		}

		cout << endl;
	}

};