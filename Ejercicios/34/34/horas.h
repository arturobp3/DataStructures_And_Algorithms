#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Horas{

private:

	int horas;
	int minutos;
	int segundos;

	static bool check(int h, int m, int s) {
		return h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
	}

public:

	Horas(int hh = 0, int mm = 0, int ss = 0){
		if (!check(hh, mm, ss)){
			throw exception();
		}
		else{
			horas = hh;
			minutos = mm;
			segundos = ss;
		}
	
	};

	int getHoras() const{
		return horas;
	}

	int getMinutos() const{
		return minutos;
	}

	int getSegundos() const{
		return segundos;
	}

	bool operator<(const Horas & dato) const{
		return (this->horas < dato.horas ||
			this->horas == dato.horas && this->minutos < dato.minutos ||
			this->horas == dato.horas && this->minutos == dato.minutos && this->segundos < dato.segundos);
	};

	bool operator==(const Horas & dato) const{
		return (this->horas == dato.horas && this->minutos == dato.minutos && this->segundos == dato.segundos);
	};

	Horas operator-(const Horas & dato) const{
		Horas resultado;
		
		resultado.segundos = abs(this->segundos - dato.segundos);
		resultado.minutos = abs(this->minutos - dato.minutos);
		resultado.horas = abs(this->horas - dato.horas);

		return resultado;
	}

	Horas operator+(const Horas & dato) const{
		Horas resultado;
		

		resultado.segundos = this->segundos + dato.segundos;
		if (resultado.segundos > 59){
			resultado.minutos += resultado.segundos / 60;
			resultado.segundos = resultado.segundos % 60;
		}

		resultado.minutos += this->minutos + dato.minutos;
		if (resultado.minutos > 59){
			resultado.horas += resultado.minutos / 60;
			resultado.minutos = resultado.minutos % 60;
		}
		resultado.horas += this->horas + dato.horas;
		if (resultado.horas > 23){
			throw exception();
		}

		return resultado;

	}

	void print(std::ostream & out = std::cout) const{
		out << std::setfill('0') << std::setw(2) << horas << ':'
			<< std::setfill('0') << std::setw(2) << minutos << ':'
			<< std::setfill('0') << std::setw(2) << segundos;
	};

	void read(std::istream & in = std::cin){
		int h, m, s;
		char aux;

		in >> h;
		in >> aux;
		in >> m;
		in >> aux;
		in >> s;

		if (!check(h, m, s)){
			throw exception();
		}
		else{
			horas = h;
			minutos = m;
			segundos = s;
		}


	}

};
