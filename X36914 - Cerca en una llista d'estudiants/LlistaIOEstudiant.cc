#include "LlistaIOEstudiant.hh"
#include <list>

void LlegirLlistaEstudiant(list<Estudiant>& l) {
  list<Estudiant>::iterator it = l.begin();
  Estudiant est;
  est.llegir();
  while (est.consultar_DNI() != 0) {
    l.insert(it, est);
    est.llegir();
  }
}

void EscriureLlistaEstudiant(list<Estudiant>& l) {
  list<Estudiant>::iterator it = l.begin();
  while (it != l.end()) {
    (*it).escriure();
    ++it;
  }
}
