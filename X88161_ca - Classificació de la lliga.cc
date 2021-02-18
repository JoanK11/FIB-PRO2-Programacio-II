#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< pair<int, int> > Row;
typedef vector<Row> Matrix;

struct equip {
    int num, punts, golsf, golsc;
};

bool comp(const equip& a, const equip& b) {
    if (a.punts == b.punts) {
        int dif1 = a.golsf - a.golsc, dif2 = b.golsf - b.golsc;
        if (dif1 == dif2) return a.num < b.num;
        return dif1 > dif2;
    }
    return a.punts > b.punts;
}

void actualitza_partit(const Matrix& m, vector<equip>& v, int i, int j) {
    // Actualitza els punts, gols a favor i gols en contra de cada equip
    // despres d'un partit
        int g1 = m[i][j].first, g2 = m[i][j].second;
        v[i].golsf += g1;
        v[j].golsf += g2;
        v[i].golsc += g2;
        v[j].golsc += g1;
        
        if (g1 == g2) ++v[i].punts, ++v[j].punts;
        else if (g1 > g2) v[i].punts += 3;
        else v[j].punts += 3;
}        

Matrix read_matrix(int n, vector<equip>& v) {
    Matrix m(n, Row(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j].first >> m[i][j].second;
            if (i != j) actualitza_partit(m, v, i, j); 
        }
    }
    return m;
}

void inicialitza(vector<equip>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i)
        v[i].num = i + 1, v[i].punts = 0, v[i].golsf = 0, v[i].golsc = 0;
}

int main() {
    int n;
    cin >> n;
    vector<equip> v(n);
    inicialitza(v);
    Matrix m = read_matrix(n, v);
    
    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < n; ++i) {
        cout << v[i].num << ' ' << v[i].punts << ' ' << v[i].golsf << ' ' << v[i].golsc << endl;
    }
}
