#include <stdio.h>
#include <iostream>
#include <string>
/*#include <iomanip>
#include <locale>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath*/
using namespace std;


template<class T>
string format(T value)
{
	stringstream ss;
	ss.imbue(locale(""));
	ss << fixed << value;
	return ss.str();
}


bool casoDePrueba() {
	
	string num;
	int out = 0;

	cin >> num;

	string outS = num;

	if (!cin)
		return false;
	else {
		int n, carry = 0;
		bool llevar = false;
		int j = num.length() - 1;
		char n_char;
		
		for (int i = num.length() - 1; i >= 0; i--){
			n_char = getchar();

		}


			/*if (num[i] != '.'){
				n += carry;
				if (i == num.length() - 1){
					n += 1;
				}

				carry = n / 10;

				if (llevar){
					out = n * pow(10, num.length() - j - 1);
					if (carry == 0){
						llevar = false;
					}
				}
				else if (carry == 1){
					n = 10;
					llevar = true;
					out = n * pow(10, num.length() - j - 1);
				}
				else{
					if (llevar){
						llevar = false;
					}
					out += n * pow(10, num.length() - j - 1);
				
			j--;
		}*/


		//cout << format(out) << endl;

		cout << outS << endl;


		return true;
	}
}


int main() {
	while (casoDePrueba()) {
	}

	return 0;
}