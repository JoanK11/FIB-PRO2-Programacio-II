#include <iostream>
#include <stack>
using namespace std;

bool isOpen(char c) { return c == '(' or c == '['; }

int main() {
    stack<char> S;
    char c;
    cin >> c;
    bool correcte = true;
    
    while (correcte and c != '.') {
        if (isOpen(c)) S.push(c);
        else if (S.empty()) correcte = false;
        else if ((c == ')' and S.top() == '(') or (c == ']' and S.top() == '[')) S.pop();
        cin >> c;
    }
    
    if (S.empty() and correcte) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
