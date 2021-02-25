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
    pair<int, int> p;
    p.first = 0, p.second = 0;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].consultar_nota() > v[p.first].consultar_nota() or
            (v[i].consultar_nota() == v[p.first].consultar_nota() and v[i].consultar_dni() > v[p.first].consultar_dni()))
            p.first = i;
        else if (v[i].consultar_nota() < v[p.second].consultar_nota() or 
            (v[i].consultar_nota() == v[p.second].consultar_nota() and v[i].consultar_dni() > v[p.second].consultar_dni()))
            p.second = i;
    }
