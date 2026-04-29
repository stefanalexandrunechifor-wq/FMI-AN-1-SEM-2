#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string a;
    int k;
    cin >> a >> k;
    stack<char> litere;
    stack<int> contor;
    for (int i = 0; i < a.length(); i++) {
        if (litere.empty() || a[i] != litere.top()) {
            litere.push(a[i]);
            contor.push(1);
        } else {
            litere.push(a[i]);
            contor.push(contor.top() + 1);
        }

        if (contor.top() == k) {
            for (int j = 0; j < k; j++) {
                litere.pop();
                contor.pop();
            }
        }
    }

    string rezultat = "";
    while (!litere.empty()) {
        rezultat += litere.top();
        litere.pop();
    }

    int stanga = 0;
    int dreapta = rezultat.length() - 1;
    while (stanga < dreapta) {
        swap(rezultat[stanga], rezultat[dreapta]);
        stanga++;
        dreapta--;
    }

    cout << rezultat ;

    return 0;
}