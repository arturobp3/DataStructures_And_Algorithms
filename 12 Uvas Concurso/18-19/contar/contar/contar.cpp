#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool casoDePrueba() {

	char c = ' ';


	cin.get(c);

	if (!cin){
		return false;
	}
	else{
		vector<char> num;
		vector<char> uno;
		int n;

		while (c != '\n'){

			if (c == '.'){
				num.push_back('.');
				uno.push_back('.');
			}
			else{
				num.push_back(c);
				uno.push_back('0');
			}
			
			cin.get(c);
			if (c == '\n'){
				uno.pop_back();
				uno.push_back('1');
			}
		}

		vector<char> res(num.size(), 0);
		int a, b, c;
		bool guardarCarry = false;
		for (int i = num.size() - 1; i >= 0; i--){

			//si es un punto,poner punto
			if (num[i] == '.'){
				res[i] = '.';
			}
			else{
				a = num[i] - '0';
				b = uno[i] - '0';
				c = a + b;

				if (c / 10 == 1){ // Hay carry
					res[i] = '0';
					if (i - 1 >= 0){
						if (uno[i - 1] != '.'){
							uno[i - 1] = '1';
						}
						else{
							if (i - 2 >= 0){
								uno[i - 2] = '1';
							}
						}
					}
					else{
						// si no hay anterior
			
						if (res.size() >= 3 && res[0] == '0' && res[1] == '0' && res[2] == '0'){
							res.insert(res.begin(), '.');
						}
						res.insert(res.begin(), '1');
					}
				}
				else{ // No hay carry
					res[i] = (char)(c + '0');
				}
			}
		}


		for (char c : res){
			cout << c;
		}

		cout << endl;


	}

	return true;
}




int main() {
	while (casoDePrueba()) {
	}

	return 0;
}