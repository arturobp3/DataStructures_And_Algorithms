#ifndef bintree_ext_h
#define bintree_ext_h

#include "bintree_eda.h"

using namespace std;


template <class T>
class bintree_ext : public bintree<T>{
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}


	
	bool esBinario(){
		T r;
		return (binario(this->raiz, r));
	}


private:

	bool binario(Link a, T &ra){
		bool binIzq, binDcha;
		int raiz1, raiz2;

		if (a == nullptr){ // Si el arbol es vacio
			ra = -1; 
			return true;
		}
		else if (this->esHoja(a)){ //Si es hoja
			ra = a->elem; 
			return true;
		}

		binIzq = binario(a->left, raiz1);
		binDcha = binario(a->right, raiz2);


		if (binIzq && binDcha){

			if ((raiz1 < a->elem) && (raiz2 > a->elem)){ //Si es binario ese arbol
				ra = a->elem;
				return true;
			}
			else if (raiz1 == -1 && a->elem < raiz2){ //Si el hijo izquierdo no tiene raiz y en el otro se cumple la condicion
				ra = a->elem;
				return true;
			}
			else if (raiz2 == -1 && a->elem > raiz1){ //Si  el hijo derecho no tiene raiz y en el otro se cumple la condicion
				ra = a->elem;
				return true;
			}
			else{             
				return false;
			}
		}
		else{
			return false;
		}

	}

	bool esHoja(Link a){
		return ((a != nullptr) && (a->left == nullptr) && (a->right == nullptr));
	}

};

template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return{ iz, raiz, dr };
	}
}


#endif