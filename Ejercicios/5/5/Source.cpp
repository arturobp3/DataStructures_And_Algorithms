#include <iostream>
#include <vector>
using namespace std;


void implementacion(vector<int> edificios, int alturaT, int & inicioIntervalo, int & finalIntervalo);



void casoDePrueba() {

	int numEdificios, alturaT;

	cin >> numEdificios >> alturaT;

	vector<int> edificios(numEdificios);

	for (int i = 0; i < edificios.size(); i++){
		cin >> edificios[i];
	}

	int inicioIntervalo = + 1;
	int final_ = 0;
	implementacion(edificios, alturaT, inicioIntervalo, final_);


	cout << inicioIntervalo << " " << final_ << "\n";


} // casoDePrueba


int main() {

	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}

//Precondición: { edificios.Length > 0 && finalIntervalo == 0 }
void implementacion(vector<int> edificios, int alturaT, int & inicioIntervalo, int & finalIntervalo){
/*Postcondición: { inicioIntervalo = exists k:: 0 <= k <= edificios.Length &&
				   finalIntervalo = exists k':: 0 <= k' <= edificios.Length &&
				   forall s:: k <= s <= k' ==> edificios[s] > alturaT}
*/
	int inicioAux, finalAux;
	int i = 0;


	/*Invariante:  0 <= i <= n &&
		inicioIntervalo = exists k:: 0 <= k <= i && 
		finalIntervalo = exists k':: 0 <= k' <= i &&
		forall s:: k <= s <= k' ==> edificios[s] > alturaT}
	*/
	while (i < edificios.size()){

		if (edificios[i] <= alturaT) i++;
		else{

			inicioAux = i;
			while (i < edificios.size() && edificios[i] > alturaT){
				i++;
			}
			finalAux = i - 1;

			if (finalAux - inicioAux > finalIntervalo - inicioIntervalo){
				inicioIntervalo = inicioAux;
				finalIntervalo = finalAux;
			}
		}

		//Funcion de cota: edificios.size() - i
	}

	//Coste: El coste de la función es del orden de 'n' (lineal), siendo n el número de edificios
	//		 Es lineal puesto que para resolver el problema en el peor de los casos (en el que edificios[i] > alturaT)
	//		 se recorre una vez el array

}