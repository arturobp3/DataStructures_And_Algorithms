#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool casoDePrueba() {
	
	int iluminadas;

	cin >> iluminadas;

	if (!cin)
		return false;
	else {

		int visitar, leido, satis1 = 0, satis2 = 0, asombro = 0, resta, cmp;
		vector<int> espect;

		cin >> visitar;
		for (int i = 0; i < iluminadas; i++){
			cin >> leido;
			espect.push_back(leido);
		}


		for (int i = 0; i < visitar - 1; i++){

			resta = abs(espect[i] - espect[i + 1]);

			if (i == 0){
				cmp = resta;
			}
			else{
				cmp = asombro;
			}

			if (cmp < espect[i + 1]){
				asombro += resta;
			}
			else if (cmp > espect[i + 1]){
				asombro -= resta;
			}
		}

		satis1 = asombro;
		asombro = 0;

		int j = 0;
		for (int i = espect.size() - 1; j < visitar - 1; i--){

			resta = abs(espect[i] - espect[i - 1]);

			if (i == espect.size() - 1){
				cmp = resta;
			}
			else{
				cmp = asombro;
			}


			if (cmp < espect[i - 1]){
				asombro += resta;
			}
			else if (cmp > espect[i - 1]){
				asombro -= resta;
			}

			j++;
		}

		satis2 = asombro;

		int mayor;

		if (satis1 >= satis2){
			mayor = satis1;
		}
		else{
			mayor = satis2;
		}


		if ((satis1 + satis2) >= mayor){
			cout << satis1 + satis2 << endl;
		}
		else{
			cout << mayor << endl;
		}


		return true;
	}
}


int main() {
	while (casoDePrueba()) {
	}

	return 0;
}