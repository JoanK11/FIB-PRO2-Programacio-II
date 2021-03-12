#include <iostream>
#include <list>
#include "LlistaIOEstudiant.hh"
#include "Estudiant.hh"

int main() {
  list<Estudiant> l;
  LlegirLlistaEstudiant(l);
  int dni;
  cin >> dni;
  
  list<Estudiant>::iterator it = l.begin();
  int x = 0;
  while (it != l.end()) {
    if ((*it).consultar_DNI() == dni) ++x;
    ++it;
  }
  
  cout << dni << ' ' << x << endl;
}
