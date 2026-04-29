#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> stanga_max;
    priority_queue<int, vector<int>, greater<int>> dreapta_min;
public:
    void addNum(int num) {
        stanga_max.push(num);
        dreapta_min.push(stanga_max.top());
        stanga_max.pop();
        if (dreapta_min.size() > stanga_max.size()) {
            stanga_max.push(dreapta_min.top());
            dreapta_min.pop();
        }
    }
    double findMedian() {
        if (stanga_max.size() > dreapta_min.size()) {
            return stanga_max.top();
        }
        return (stanga_max.top() + dreapta_min.top()) / 2.0;
    }
};
int main() {
    
    return 0;
}