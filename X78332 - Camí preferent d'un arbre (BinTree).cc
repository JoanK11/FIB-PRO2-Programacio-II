// https://jutge.org/problems/X78332_ca
#include "BinTree.hh"
#include <stack>
using namespace std;

int sum(const BinTree<int>& a) {
    if (a.empty()) return 0;
    int left = sum(a.left());
    int right = sum(a.right());
    return 1 + right + left;
}

void cami_preferent(const BinTree<int>& a, stack<int>& c) {
    if (not a.empty()) {
        int sumR = sum(a.right());
        if (sumR == 0) {
            cami_preferent(a.left(), c);
            c.push(a.value());
        }
        else {
            int sumL = sum(a.left());
            if (sumL >= sumR) cami_preferent(a.left(), c);
            else cami_preferent(a.right(), c);
            c.push(a.value());
        }
    }
}
