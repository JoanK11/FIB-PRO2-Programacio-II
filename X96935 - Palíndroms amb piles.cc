#include <iostream>
#include <stack>
using namespace std;

bool palindrom(stack<int>& S, int n) {
	int x;
	if (n%2 != 0) cin >> x;
	for (int i = 0; i < n/2; ++i) {
		cin >> x;
		if (x != S.top()) return false;
		S.pop();	
	}
	return S.empty();
}

int main() {
	int n;
	cin >> n;
	stack<int> S;
	int x;
	for (int i = 0; i < n/2; ++i) {
		cin >> x;
		S.push(x);
	}
	if (palindrom(S, n)) cout << "SI" << endl;
	else cout << "NO" << endl;
}
