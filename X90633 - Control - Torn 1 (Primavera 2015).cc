#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
	int dni = est.consultar_DNI();
	int i = cerca_dicot(vest, 0, nest - 1, dni);
	b = vest[i].consultar_DNI() == dni;
	
	if (not b) {
		int j = nest - 1;
		bool aux = false;
    	while (j >= i and not aux) {  
        	if (dni > vest[j].consultar_DNI()) aux = true;
        	else vest[j + 1] = vest[j], --j;
		}
		vest[j+1] = est;
		++nest;
		if (est.te_nota()) {
			++nest_amb_nota;
			suma_notes += est.consultar_nota();
		}
	}
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
	int i = cerca_dicot(vest, 0, nest - 1, dni);
	b = i < nest and vest[i].consultar_DNI() == dni;
	
	if (b) {
		if (vest[i].te_nota()) {
			--nest_amb_nota;
			suma_notes -= vest[i].consultar_nota();
		}
		for (int j = i; j < nest - 1; ++j) vest[j] = vest[j+1];
		--nest;
	}
}
