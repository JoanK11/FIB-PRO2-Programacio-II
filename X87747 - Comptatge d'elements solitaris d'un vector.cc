#include <iostream>
#include <vector>
using namespace std;

int solitaris(const vector<int>& v) {
    int n = v.size(), count = 0;
    if (n == 1) return 1;
    
    if (v[0] != v[1]) ++count;
    for (int i = 1; i < n - 1; ++i) {
        if (v[i-1] != v[i] and v[i] != v[i+1]) ++count;
    }
    if (v[n-1] != v[n-2]) ++count;
    return count;
}
