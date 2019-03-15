#ifndef PELICULA_H
#define PELICULA_H

#include "horas.h"
#include <string>
using namespace std;


class Pelicula{

private:
	Horas inicio, duracion;
	string nombre;

public:

	Pelicula(Horas i, Horas d, string n) : inicio(i), duracion(d), nombre(n){};

	bool operator<(const Pelicula & dato) const{
		if((this->inicio + this->duracion) < (dato.inicio + dato.duracion)) return true;
		else if ((this->inicio + this->duracion) == (dato.inicio + dato.duracion) && this->nombre < dato.nombre) return true;
		else return false;
	}

	Horas getFinalizacion() const{
		return this->inicio + this->duracion;
	}

	string getNombre() const{
		return nombre;
	}

};


#endif
