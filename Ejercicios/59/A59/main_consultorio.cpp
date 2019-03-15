
#include <iostream>
#include <fstream>
#include "consultorio.h"

using namespace std;

void listarPacientes(consultorio & h, const string & medico, int dia);

bool resuelveCaso() {

   string orden, paciente, medico;
   int ordenes;
   int i = 0;
   int dia, hora, minutos;

   cin >> ordenes;

   if (!cin)
      return false;
   
   consultorio H;

   cin >> orden;

   while (i < ordenes) {

      try {

         if (orden == "nuevoMedico") {
            cin >> medico;
            H.alta_medico(medico);
         } 

		 else if (orden == "pideConsulta") {
            cin >> paciente >> medico >> dia >> hora >> minutos;

			Fecha nuevaFecha(dia, hora, minutos);

            H.pedir_consulta(paciente, medico, nuevaFecha);
         }

		 else if (orden == "atiendeConsulta") {
            cin >> medico;
			H.atender_consulta(medico);
         } 

		 else if (orden == "siguientePaciente") {
            cin >> medico;
            paciente = H.siguiente_paciente(medico);

            cout << "Siguiente paciente doctor " << medico << '\n';
			cout << paciente << endl;
			cout << "---" << endl;
         }
		 
		 else if (orden == "listaPacientes"){
			 cin >> medico >> dia;
			 listarPacientes(H, medico, dia);
			 cout << "---" << endl;
		 }


      } catch (domain_error e) {
         cout << e.what() << '\n';
		 cout << "---" << endl;
      }

	  i++;
	  if (i < ordenes) cin >> orden;
   }

   cout << "------\n";

   return true;
}


void listarPacientes(consultorio & h, const string & medico, int dia){
	map<Fecha, paciente> mp = h.listaPacientes(medico, dia);
	auto it = mp.begin();

	cout << "Doctor " << medico << " dia " << dia << endl;
	while (it != mp.end()){
		cout << it->second << " ";
		cout << std::setfill('0') << std::setw(2) << it->first.getHoras() << ':'
			<< std::setfill('0') << std::setw(2) << it->first.getMinutos();
		cout << endl;
		++it;
	}
}

int main() {

   while (resuelveCaso());
 
   return 0;
}

