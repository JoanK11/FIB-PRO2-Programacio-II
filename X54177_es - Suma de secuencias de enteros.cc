#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        int sum = 0, y;
        cin >> y;
        while (y != x) {
            sum += y;
            cin >> y;
        }
        string s;
        getline(cin, s);
        cout << "La suma de la secuencia " << i << " es " << sum << endl;
    }
}
s
