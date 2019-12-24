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
	int horaEnSegundos;

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
			horaEnSegundos = horas * 3600 + minutos * 60 + segundos;
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


	static int compare(int segs, Horas & h2) {
		return segs - h2.horaEnSegundos;
	}

	//Resta de horas utilizando los segundos. Devuelve los segundos
	int operator-(Horas & dato) const{

		int difSegundos = compare(this->horaEnSegundos, dato);
		if (difSegundos < 0) {
			difSegundos = 86400 + difSegundos;
		}
		return difSegundos;
	}

	// Suma segundos a una hora
	Horas suma(int s) {
		Horas resultado;

		horaEnSegundos += s;
		if (horaEnSegundos >= 86400) {
			horaEnSegundos -= 86400;
		}
		resultado.horas = (int)(horaEnSegundos / 3600);
		resultado.minutos = (int)((horaEnSegundos % 3600) / 60);
		resultado.segundos = (int)(horaEnSegundos % 60);

		return resultado;
	}

	//Suma dos horas. Esta funcion está mal por alguna razón
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
			resultado.horas = 0;
		}

		return resultado;

	}

	static Horas secsToHour(const int & secs){
		Horas result;

		result.minutos = secs / 60;
		result.segundos = secs % 60;
		result.horas = result.minutos / 60;
		result.minutos = result.minutos % 60;

		result.horaEnSegundos = result.horas * 3600 + result.minutos * 60 + result.segundos;

		return result;
	}


	static int hourToSecs(const Horas & dato){
		int secs = 0;

		secs += (dato.getHoras() * 60 * 60);
		secs += (dato.getMinutos() * 60);
		secs += (dato.getSegundos());

		return secs;
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
			horaEnSegundos = horas * 3600 + minutos * 60 + segundos;
		}
	}

};
