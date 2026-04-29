#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, s;
    if (!(cin >> n >> s)) return 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int current_sum = a[i].first + a[left].first + a[right].first;
            if (current_sum == s) {
                int result_indices[] = {a[i].second, a[left].second, a[right].second};
                sort(result_indices, result_indices + 3);
                cout << result_indices[0] << " " << result_indices[1] << " " << result_indices[2] << "\n";
                return 0;
            }
            if (current_sum < s) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return 0;
}