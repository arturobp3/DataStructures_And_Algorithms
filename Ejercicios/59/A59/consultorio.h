
#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <map>
#include "fecha.h"
using namespace std;

using medico = string;
using paciente = string;


class consultorio : private unordered_map<medico, map<Fecha, paciente>> {
 
private: 

	map<Fecha, paciente> filtrarMapa(const medico & m, int dia){
		map<Fecha, paciente> mp;
		auto it = find(m);

		auto itMap = it->second.begin(); //Iterador al primer elemento del map
		
		while (itMap != it->second.end()){ //Mientras no llegue al fin

			if (itMap->first.getDia() == dia){ //Si el dia del primer elemento es igual al dia de entrada
				mp.insert( {itMap->first, itMap->second} ); //Inserta un nuevo par al mapa
			}

			++itMap;
		}

		return mp;
	}


public:

   void alta_medico(medico const& m) {
	   if (!insert({ m, map<Fecha, paciente>() }).second){}
   }


   void pedir_consulta(paciente const& p, medico const& m, const Fecha & f) {
       auto it = find(m);
       if (it == end())
           throw domain_error("Medico no existente");
	   else{
		   if (it->second.count(f)){ //Si ha encontrado esa hora en la lista de horas del medico
			   throw domain_error("Fecha ocupada");
		   }
		   else{
			   it->second.insert({ f, p });  //Si no la ha encontrado inserta el nuevo par en el mapa ordenado
		   }
	   }
           
   }

   bool tiene_pacientes(medico const& m) const {
       auto it = find(m);
       if (it == end())
		   throw domain_error("Medico no existente");
       else
           return !it->second.empty();
   }

   paciente siguiente_paciente(medico const& m) const {
       auto it = find(m);
	   if (it == end()){
		   throw domain_error("Medico no existente");
	   }
	   else{
		   if (it->second.empty())
			   throw domain_error("No hay pacientes");
		   else{

			   map<Fecha, paciente> mp = it->second;

			   auto it2 = mp.begin(); //Iterador al primer elemento del mapa

			   return it2->second; //Devuelve el paciente
		   }  
	   }
   }

   void atender_consulta(medico const& m) {
       auto it = find(m);
       if (it == end())
		   throw domain_error("Medico no existente");
       else
           if (it->second.empty())
			   throw domain_error("No hay pacientes");
		   else{

			   map<Fecha, paciente> mp = it->second;
			   auto it2 = mp.begin(); //Iterador al primer elemento del mapa

			   it->second.erase(it2->first); //Borra el primer elemento del map (lo borra por clave)
		   }
   }

   map<Fecha, paciente> listaPacientes(medico const & m, int dia){
	   map<Fecha, paciente> mp;
	   auto it = find(m);

	   if (it == end()) throw domain_error("Medico no existente");
	   else{
		   if (tiene_pacientes(m)){
			  
			   mp = filtrarMapa(m, dia);

			  return mp;
		   }
		   else{
			   return mp;
		   }
	   }
   }
};



#endif
