#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        heap.push(d);
    }
    long long cost_total = 0;
    while (heap.size() > 1) {
        long long primul = heap.top();
        heap.pop();
        long long al_doilea = heap.top();
        heap.pop();
        long long cost_interclasare = primul + al_doilea;
        cost_total += cost_interclasare;
        heap.push(cost_interclasare);
    }
    cout << cost_total << endl;
    return 0;
}