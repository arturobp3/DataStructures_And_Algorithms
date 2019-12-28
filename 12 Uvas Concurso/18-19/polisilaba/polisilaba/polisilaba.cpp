#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;



void casoDePrueba() {

	string str1, str2, medio;

	cin >> str1 >> medio >> str2;


	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	if (str1 == str2){
		cout << "TAUTOLOGIA" << endl;
	}
	else{
		cout << "NO TAUTOLOGIA" << endl;
	}

} 




int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;
}