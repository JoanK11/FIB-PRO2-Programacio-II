#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"

int main() {
  list<ParInt> l;
  LlegirLlistaParInt(l);
  int n, count = 0, sum = 0;
  cin >> n;
  
  list<ParInt>::iterator it = l.begin();
  while (it != l.end()) {
    if ((*it).primer() == n) ++count, sum += (*it).segon();
    ++it;
  }
  
  cout << n << ' ' << count << ' ' << sum << endl;
}
