#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> d;
    long long suma = 0;
    for (int i = 0; i < n; i++) {
        while (!d.empty() && a[d.back()] >= a[i]) {
            d.pop_back();
        }
        d.push_back(i);
        if (d.front() <= i - k) {
            d.pop_front();
        }
        if (i >= k - 1) {
            suma += a[d.front()];
        }
    }

    cout << suma;
    return 0;
}