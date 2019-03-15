#ifndef fecha_h
#define fecha_h
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class Fecha{

private:

	int dia;
	int horas;
	int minutos;


public:

	Fecha(int dd = 0, int hh = 0, int mm = 0){
		dia = dd;
		horas = hh;
		minutos = mm;

	};

	int getDia()const{
		return dia;
	}

	int getHoras()const{
		return horas;
	}

	int getMinutos()const{
		return minutos;
	}


	bool operator<(const Fecha & dato) const{
		return (this->dia < dato.dia ||
			this->dia == dato.dia &&  this->horas < dato.horas ||
			this->dia == dato.dia &&  this->horas == dato.horas && this->minutos < dato.minutos);
	};

	bool operator==(const Fecha & dato) const{
		return (this->dia == dato.dia && this->horas == dato.horas && this->minutos == dato.minutos);
	};


	void print(std::ostream & out = std::cout) const{
		out << std::setfill('0') << std::setw(2) << horas << ':'
			<< std::setfill('0') << std::setw(2) << minutos;
	};

};
#endif
