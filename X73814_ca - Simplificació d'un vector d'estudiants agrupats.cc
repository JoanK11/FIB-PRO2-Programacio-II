#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, double> > simplifica(const vector< pair<int, double> >& v) {
    int n = v.size(), j = 0; // j = posicio de l'ultim element al vector r
    // Inicialitzem un vector r amb el primer valor de v
    vector< pair<int, double> > r(1, v[0]);
    for (int i = 1; i < n; ++i) {
        r.push_back(v[i]);
        if (r[j].first == v[i].first) { // Si ja estava el DNI fem pop_back()
            r.pop_back();
            // Si la nota es mes alta la canviem
            if (r[j].second < v[i].second) r[j].second = v[i].second;
        }
        else ++j; // S'ha afegit una nova posició al vector
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    // Llegim el vector original
    vector< pair<int, double> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (v[i].second > 10) v[i].second = -1; // Nota = {-1}, [0, 10]
    }
    
    vector< pair<int, double> > result = simplifica(v);
    n = result.size();
    for (int i = 0; i < n; ++i) {
        cout << result[i].first << ' ';
        if (result[i].second < 0) cout << "NP" << endl;
        else cout << result[i].second << endl;
    }
}
