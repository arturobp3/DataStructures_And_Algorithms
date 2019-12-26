#include <iostream>
#include <string>
using namespace std;


bool casoDePrueba() {
	string in;

	cin >> in;

	if (!cin){
		return false;
	}
	else {
		
		for (int i = 0; i < in.length(); i++){
			cout << in[i];
			if (i < in.length() - 1)
				cout << "0";
		}

		cout << endl;

		return true;
	}
}


int main() {
	while (casoDePrueba()) {
	}

	return 0;
}