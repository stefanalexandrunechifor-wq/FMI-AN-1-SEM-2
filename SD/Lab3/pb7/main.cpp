#include <iostream>
#include <vector>
#include <random> // Pentru mt19937_64
using namespace std;
const int MAX_N = 300005;
int main() {
    mt19937_64 rng(1337);
    vector<unsigned long long> cod(MAX_N);
    vector<unsigned long long> amprenta_corecta(MAX_N, 0);
    unsigned long long COD_INVALID = rng();
    for (int i = 0; i < MAX_N; ++i) {
        cod[i] = rng();
        if (i > 0) {
            amprenta_corecta[i] = amprenta_corecta[i - 1] + cod[i - 1];
        }
    }
    vector<int> a;
    vector<unsigned long long> pref;
    pref.push_back(0);
    int x,y;
    while (cin >> x) {
        a.push_back(x);
        unsigned long long hash_curent;
        if (x < MAX_N) {
            hash_curent = cod[x];
        } else {
            hash_curent = COD_INVALID;
        }
        pref.push_back(pref.back() + hash_curent);
    }
    while (cin>>x>>y) {
        if (pref[y]-pref[x-1]==) {

        }
    }
}