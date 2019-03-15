#include "bintree_eda.h"

using namespace std;


template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}


	vector<T> calculaFronteraPostOrden(){
		vector<T> frontera;

		postorder2(this->raiz, frontera);

		return	frontera;
	}

private:

	void postorder2(Link a, std::vector<T> & post) {

		if (a != nullptr) {
			postorder2(a->left, post);
			postorder2(a->right, post);

			if (a->left == nullptr && a->right == nullptr){ //Si los hijos son nulos estamos ante un nodo hoja
				post.push_back(a->elem);
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