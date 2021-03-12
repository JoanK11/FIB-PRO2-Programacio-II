#include <list>
#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  list<ParInt>::iterator it = l.begin();
  ParInt p;
  while (p.llegir()) {
    l.insert(it, p);
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  list<ParInt>::const_iterator it = l.begin();
  while (it != l.end()) {
    (*it).escriure();
    ++it;
  }
}
