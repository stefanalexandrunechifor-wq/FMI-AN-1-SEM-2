#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
long long maxim(const vector<int>& a, int k) {
    if (k < 0) return 0;

    int st = 0;
    long long total = 0;
    int distincte = 0;
    unordered_map<int, int> cnt;
    for (int dr = 0; dr < a.size(); ++dr) {
        if (cnt[a[dr]] == 0) {
            distincte++;
        }
        cnt[a[dr]]++;
        while (distincte > k) {
            cnt[a[st]]--;
            if (cnt[a[st]] == 0) {
                distincte--;
            }
            st++;
        }
        total += (dr - st + 1);
    }
    return total;
}
long long numara_secv(const vector<int>& a, int l, int u) {
    return maxim(a, u) - maxim(a, l - 1);
}
int main() {
    vector<int> a = {1, 2, 1, 2, 3};
    int l = 2;
    int u = 3;
    cout << numara_secv(a, l, u) << "\n";
    return 0;
}