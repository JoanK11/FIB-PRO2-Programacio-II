#include <iostream>
#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int>& v) {
    int n = v.size();
    if (n == 0) return 0;
    
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) right += v[i];
    
    // Comencem la cerca
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == right - left) ++count;
        left += v[i], right -= v[i+1];
    }
    if (v[n-1] == -left) ++count;
    return count;
}
