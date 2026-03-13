#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct exercitiu {
    vector<int> v;
    void insert(int x) {
        v.push_back(x);
    }
    void pop() {
        swap(v[v.size()-1],v[random()]);
        v.pop_back();
    }
    int random() {
        if (v.size() != 0)
        {
            int randomnum=rand()%(v.size());
            return randomnum;
        }
        return 0;
    }
    void afisare() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    srand(time(NULL));
    exercitiu v;
    v.insert(4);
    v.insert(5);
    v.insert(6);
    v.insert(7);
    v.insert(8);
    v.pop();
    v.afisare();
    return 0;
}