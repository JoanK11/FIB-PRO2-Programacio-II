#include <list>
using namespace std;

void seleccio(const list<double>& l, list<double>& sel) {
  list<double>::const_iterator it1 = l.begin();
  list<double>::iterator it2 = sel.begin();
  double mitjana = *it1;
  int n = 1;
  sel.insert(it2, *it1);
  ++it1;
  while (it1 != l.end()) {
    if (*it1 >= mitjana/n) sel.insert(it2, *it1);
    mitjana += *it1, ++it1, ++n;
  }
}
