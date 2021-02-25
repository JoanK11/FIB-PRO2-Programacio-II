#include <vector>
#include "Estudiant.hh"
using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos) {
/* Pre: v = V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos + 1 es el nombre d'estudiants diferents de V; cada estudiant de V
   nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
   ordre que a V */
   int n = v.size(), j = 0;
   for (int i = 1; i < n; ++i) {
       int dni1 = v[i].consultar_DNI(), dni2 = v[j].consultar_DNI();
       double nota1 = v[i].consultar_nota(), nota2 = v[j].consultar_nota();
       if (dni1 == dni2 and nota1 > nota2) v[j].modificar_nota(nota1);
       else if (dni1 != dni2) ++j, v[j] = v[i];
   }
   while (v.size() > j + 1) v.pop_back();
   pos = v.size();
}
