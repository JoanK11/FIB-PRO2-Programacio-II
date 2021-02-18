#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

double mitjana(const vector<int>&v, int n) {
    vector<double> notes(n);
    for (int i = 0; i < n; ++i) cin >> notes[i];
    double total = 0;
    n = v.size();
    for (int i = 0; i < n; ++i) total += notes[v[i] - 1];
    return total/n;
}

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<int> v(s);
    for (int i = 0; i < s; ++i) cin >> v[i];
    
    for (int i = 0; i < m; ++i) {
        int dni;
        cin >> dni;
        cout << dni << ' ' << mitjana(v, n) << endl;
    }
}
