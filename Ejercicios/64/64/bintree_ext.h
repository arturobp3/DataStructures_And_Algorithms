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


	bool esZurdo(){ 
		bool z;
		int nodos = this->zurdo(this->raiz, z);

		return z;
	}

private:

	int zurdo(Link a, bool & z){ //Devuelve el numero de nodos en cada hijo
		int nodosIzq, nodosDcha;
		bool zurdoIzq, zurdoDcha;

		if (a == nullptr){ //Arbol vacío
			z = true;
			return 0;

		}
		else if (this->esHoja(a)){ //Es una hoja
			z = true;
			return 1;
		}
		else{
			nodosIzq = zurdo(a->left, zurdoIzq);
			nodosDcha = zurdo(a->right, zurdoDcha);

			z = (zurdoIzq && zurdoDcha && (nodosIzq > nodosDcha));
			return (nodosIzq + nodosDcha + 1);
		}
	}

	bool esHoja(Link a){
		return ( (a != nullptr) && (a->left == nullptr) && (a->right == nullptr) );
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