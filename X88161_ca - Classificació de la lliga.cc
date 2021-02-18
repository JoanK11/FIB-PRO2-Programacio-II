#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< pair<int, int> > Row;
typedef vector<Row> Matrix;

struct equip {
    int num, punts = 0, golsf = 0, golsc = 0;
};

bool comp(const equip& a, const equip& b) {
    if (a.punts == b.punts) {
        int dif1 = a.golsf - a.golsc, dif2 = b.golsf - b.golsc;
        if (dif1 == dif2) return a.num < b.num;
        return dif1 > dif2;
    }
    return a.punts > b.punts;
}

void actualitza_partit(vector<equip>& v, int i, int j, int g1, int g2) {
    // Actualitza els punts, gols a favor i gols en contra de cada equip
    // despres d'un partit
        v[i].golsf += g1, v[j].golsf += g2;
        v[i].golsc += g2, v[j].golsc += g1;
        
        if (g1 == g2) ++v[i].punts, ++v[j].punts;
        else if (g1 > g2) v[i].punts += 3;
        else v[j].punts += 3;
}        

void lectura_partits(vector<equip>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int g1, g2;
            cin >> g1 >> g2;
            if (i != j) actualitza_partit(v, i, j, g1, g2); 
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<equip> v(n);
    for (int i = 0; i < n; ++i) v[i].num = ++i; // Posem el num de cada equip
    
    lectura_partits(v); // Llegim tots els partits
    sort(v.begin(), v.end(), comp); // Ordenem els equips
    
    for (int i = 0; i < n; ++i) {
        cout << v[i].num << ' ' << v[i].punts << ' ' << v[i].golsf << ' ' << v[i].golsc << endl;
    }
}
