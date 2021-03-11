#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< stack<string> > v(n);
    int x;
    cin >> x;
    while (x != -4) {
        if (x == -1) {
            string nom;
            int i;
            cin >> nom >> i;
            v[i-1].push(nom);
        }
        
        else if (x == -2) {
            int ret, i;
            cin >> ret >> i;
            while (ret > 0) v[i-1].pop(), --ret;
        }
        
        else if (x == -3) {
            int i;
            cin >> i;
            cout << "Pila de la categoria " << i << endl;
            stack<string> Aux(v[i-1]);
            
            while (not Aux.empty()) {
                cout << Aux.top() << endl;
                Aux.pop();
            }
            cout << endl;
        }
        cin >> x;
    }
}
