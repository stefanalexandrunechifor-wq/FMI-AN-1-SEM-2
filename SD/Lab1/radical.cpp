#include <iostream>

using namespace std;

int radical(int n) {
    if (n <= 1) return n;
    int st = 0, dr = n/2;
    while (st <= dr) {
        int mij = st + (dr - st)/2;
        if (mij * mij == n) return mij;
        if (mij * mij < n) st = mij + 1;
        else dr = mij - 1;
    }
    return dr;
}

int main() {
    int n;
    cin >> n;
    cout << radical(n) << endl;
    return 0;
}