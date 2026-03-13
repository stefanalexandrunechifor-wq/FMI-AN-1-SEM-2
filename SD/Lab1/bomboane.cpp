#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> bomboane(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                bomboane[i] = bomboane[i-1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                bomboane[i] = max(bomboane[i], bomboane[i+1] + 1);
            }
        }
        return bomboane;
    }
};
int main() {
    Solution solutie;
    int n;
    cin>>n;
    vector<int> ratings(n);
    for (int i=0;i<n;i++) {
        cin>>ratings[i];
    }
    vector<int> bomboane = solutie.candy(ratings);
    for (int i=0;i<n;i++) {
        cout<<bomboane[i]<<" ";
    }
    return 0;
}
