#include <vector>
#include "Estudiant.hh"
using namespace std;

 pair<int,int>  max_min_vest(const vector<Estudiant>& v) 
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
{
    // Primer mirem si no hi ha cap estudiant amb nota
    pair<int, int> p;
    p.first = -1, p.second = -1;
    int i = 0, n = v.size();
    while (i < n and not v[i].te_nota()) ++i;
    if (i == n) return p;
    // Algun element de v te nota
    p.first = i, p.second = i;
    ++i;
    while (i < n) {
        if (v[i].te_nota()) {
            double nota = v[i].consultar_nota();
            int dni = v[i].consultar_DNI();
            if (nota > v[p.first].consultar_nota() or (nota == v[p.first].consultar_nota() and dni < v[p.first].consultar_DNI()))
                p.first = i;
            else if (nota < v[p.second].consultar_nota() or (nota == v[p.second].consultar_nota() and dni < v[p.second].consultar_DNI()))
                p.second = i;
        }
        ++i;
    }
    return p;
}
