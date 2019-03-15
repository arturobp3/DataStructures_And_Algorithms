#include <iostream>
#include <vector>
using namespace std;

const int MAX_COLORES = 3;

//rojo, azul, verde
typedef enum colores { r, a, v };



void tratarSolucion(vector<colores> & solucion, int nivel){
	for (int i = 0; i <= nivel; i++){
		if (solucion[i] == a) cout << "azul ";
		else if (solucion[i] == r) cout << "rojo ";
		else cout << "verde ";
	}

	cout << "\n";
}

bool esSolucion(int nivel, int m){
	
	return (nivel == m - 1);
}

bool esValida(vector<colores> & solucion, int n, int azules, int rojos, int verdes){

	int i = 0;
	bool verdesJuntos = false;
	bool valido = true;

	int ve = 0;
	int az = 0;
	int ro = 0;

	//Comprueba si hay verdes juntos
	while (i <= n - 1 && !verdesJuntos){
		if (solucion[i] == v) ve++;
		if (solucion[i] == a) az++;
		if (solucion[i] == r) ro++;

		if (solucion[i] == v && solucion[i + 1] == v) verdesJuntos = true;

		else i++;
	}

	if (azules >= az && rojos >= ro && verdes >= ve && ro > az + ve) valido = true;
	if (az > ve || verdesJuntos) valido = false;

	return valido;
}



void variaciones(vector<colores> & solucion, int nivel, int n, int m, int azules, int rojos, int verdes){

	for (int pos = r; pos <= v; pos++){
		solucion[nivel] = colores(pos);

		if (esValida(solucion, n, azules, rojos, verdes)){
			if (esSolucion(nivel, m)){
				tratarSolucion(solucion, m);
			}
			else{
				variaciones(solucion, nivel + 1, n, m, azules, rojos, verdes);
			}
		}
	}
}

void variaciones(int n, int m, int azules, int rojos, int verdes){
	vector<colores> solucion(n);
	variaciones(solucion, 0, n, m, azules, rojos, verdes);
}

bool casoDePrueba() {

	int altura, azules, rojos, verdes;

	cin >> altura >> azules >> rojos >> verdes;

	if (altura == 0 && azules == 0 && rojos == 0 && verdes == 0)
		return false;
	else {
		if (altura > 1 && rojos >= 0 && azules >= 0 && verdes >= 0)
		{
			variaciones(altura, MAX_COLORES, azules, rojos, verdes);
		}
		else{
			cout << "SIN SOLUCION" << endl;
		}
		return true;
	}
} // casoDePrueba

int main() {
	while (casoDePrueba()) {
	}



	system("Pause");
	return 0;
}