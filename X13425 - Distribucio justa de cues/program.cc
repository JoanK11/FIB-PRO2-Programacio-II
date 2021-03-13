#include <iostream>
#include <queue>
#include "CuaIOParInt.hh"
#include "ParInt.hh"
using namespace std;

void repartir(queue<ParInt>& q, queue<ParInt>& q1, queue<ParInt>& q2) {
    int t1 = 0, t2 = 0;
    while (not q.empty()) {
        if (t2 < t1) {
            q2.push(q.front());
            t2 += q.front().segon();
        }
        else {
            q1.push(q.front());
            t1 += q.front().segon();
        }
        q.pop();
    }
}

int main() {
    queue<ParInt> q;
    llegirCuaParInt(q);
    
    queue<ParInt> q1, q2;
    repartir(q, q1, q2);

    escriureCuaParInt(q1);
    cout << endl;
    escriureCuaParInt(q2);
}
