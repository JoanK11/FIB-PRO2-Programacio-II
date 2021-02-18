#include <vector>
using namespace std;
 
struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v
   el segundo componente del resultado es el valor minimo de v */
{
    parint x;
    x.prim = v[0], x.seg = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i] > x.prim) x.prim = v[i];
        if (v[i] < x.seg) x.seg = v[i];
    }
    return x;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> p;
    int n = v.size();
    p.first = v[0], p.second = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] > p.first) p.first = v[i];
        if (v[i] < p.second) p.second = v[i];
    }
    return p;
}
 
void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = v[0], y = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}
