#include "bintree_eda.h"

using namespace std;


template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}


	size_t altura() const {
		return altura(this->raiz);
	}

	size_t numNodos() const{
		return nodos(this->raiz);
	}

	size_t numHojas(){
		size_t hojas = 0;

		postorder2(this->raiz, hojas);

		return hojas;
	}




private:

	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}

	static size_t nodos(Link r) {
		if (r == nullptr)
			return 0;
		else {
			return 1 + nodos(r->left) + nodos(r->right);
		}
	}

	void postorder2(Link a, size_t & numHojas) {

		if (a != nullptr) {
			postorder2(a->left, numHojas);
			postorder2(a->right, numHojas);

			if (a->left == nullptr && a->right == nullptr){ //Si los hijos son nulos estamos ante un nodo hoja
				numHojas++;
			}
		}
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