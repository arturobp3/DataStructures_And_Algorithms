#include "Monomio.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
using namespace std;


class Polinomio{

private:
	
	vector<Monomio<int, int>> v;

	int buscarPos(const vector< Monomio <int, int>> & v, const Monomio <int, int> & mon) const{
		int pos, ini = 0, fin = v.size() - 1, mitad;
		bool encontrado = false;

		while ((ini <= fin) && !encontrado){
			mitad = (ini + fin) / 2;

			if (v[mitad] < mon){
				ini = mitad + 1;
			}
			else if (mon < v[mitad]){
				fin = mitad - 1;
			}
			else encontrado = true;
		}

		if (encontrado) pos = mitad;
		else pos = ini;

		return pos;
	}

public:

	
	Polinomio(){};

	void inserta(const Monomio<int, int> & monomio){

		int sumaCoef = contiene(monomio);
		int posOrdenada = buscarPos(v, monomio); //Inserta de manera ordenada (de menor a mayor segun su exponente)

		if (sumaCoef != 0 && monomio.getCoeficiente() != 0){ //Si el coeficiente del monomio es 0, no se añade directamente

			if (sumaCoef != monomio.getCoeficiente()){//Si la suma es distinta que el coeficiente, se cambia el coeficiente
				v[posOrdenada].setCoeficiente(sumaCoef);
			}
			else{
				v.insert(v.begin() + posOrdenada, monomio); //Inserta el elemento en la posOrdenada
			}
		}

		if (sumaCoef == 0 && v.size() > 0 && monomio.getCoeficiente() != 0){ //Si la suma es 0 y hay elementos en el vector, borra el monomio
			v.erase(v.begin() + posOrdenada);								
		}

	}

	int contiene(const Monomio<int, int> & monomio) const{ //Devuelve el coeficiente del monomio si no se ha encontrado ningun monomio más con su mismo
														// exponente, ó la suma de los coeficientes de los monomios que tienen igual exponente en caso contrario
		int i = 0;
		int fin = v.size();
		int suma = monomio.getCoeficiente();

		while (i < fin){

			if(v[i].getExponente() != monomio.getExponente()) i++;
			else{
				suma = suma + v[i].getCoeficiente();
				i++;
			}
		}

		return suma;
	}

	double evaluarPolinomio(int valor) const{ //Dado un valor como variable, devuelve el resultado del monomio con esa variable

		double resultado = 0;

		for (int i = 0; i < v.size(); i++){
			resultado += v[i].getCoeficiente() * (pow(valor, v[i].getExponente()));
		}

		return resultado;
	}
};