#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

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
    
    vector< pair<int, double> > alumnes(m);
    for (int i = 0; i < m; ++i) {
        cin >> alumnes[i].first;
        alumnes[i].second = mitjana(v, n);
    }
    
    sort(alumnes.begin(), alumnes.end(), comp);
    for (int i = 0; i < m; ++i)
        cout << alumnes[i].first << ' ' << alumnes[i].second << endl;
}
