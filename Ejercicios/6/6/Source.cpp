/*
* Arturo Barbero Pérez
* Carlos Ramos Morales
* 2ºA
*/

#include <iostream>
#include <vector>
using namespace std;

int xxx(vector<int> v)
{	
	//Borra los comentarios de explicacion luego cuando se entregue con el invariante y eso

	int posicion = -1; //IMPORTANTE
	int contCeros = 0, contUnos = 0;

	if (v.size() > 0)
	{
		int k = 0;

		while(k < v.size()) // Recorremos el vector
		{
			if (v[k] == 1){  //si es un 1
				contUnos++;  //Contamos

				if (contUnos == contCeros){  //y comprobamos si hasta ese momento son iguales para guardar la posicion
					posicion = k;
					k++;
				}
				else k++; //si no son iguales seguimos hasta que lo sean
			}

			else if (v[k] == 0){ 
				contCeros++;
				if (contUnos == contCeros){
					posicion = k;
					k++;
				}
				else k++;
			}

			else k++;

			if (contCeros == contUnos) posicion = k - 1; //los casos en los que v[k] != 0 y 1, y (contCeros == contUnos) la posicion a guardar 
														//es la actual (es k-1 porque en todos los else finales se incrementa)
				
			//else posicion = -1; 

			/*El problema estaba con esto creo yo, porque cuando quite la opcion de que tuviese que dar -1, entonces en casos como: 1 1 1 1 1 daba 0
			porque la variable posicion estaba a 0. Entonces lo interprete como que no dependia de que (contCeros == contUnos) si no de que
			como al principio no se ha encontrado una posicion hasta la cual el numero de ceros y de unos sea iguales, pues no la hay.. y en ese caso
			es -1.. no se si me explico xD o sea, no es porque (contCeros != contUnos) sino porque al principio hasta que no encuentre un 0 y luego un 1
			o viceversa, no la has encontrado.
			*/
				
		}
		
		
	}
	else // Si el tamaño del vector es 0
	{
		posicion = -1;
	}


	return posicion;
}

void casoDePrueba() {

	// LECTURA DE DATOS:

	int tam; // Tamaño del vector
	cin >> tam;
	int i = 0;
	vector<int> v(tam);
	while (i < tam) // Cargamos los elementos en el vector
	{
		cin >> v[i];
		i++;
	}


	// CALCULO DEL RESULTADO:

	int p = xxx(v);


	// SALIDA:

	cout << p << "\n";

} // casoDePrueba

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}