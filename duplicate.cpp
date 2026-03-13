#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    const int size=n+1;
    int v[size];
    for (int i=0;i<size;i++) {
        cin>>v[i];
    }
    int i=0;
    int j=0;
    do {
        i=v[i];
        j=v[v[j]];
    }
    while (i!=j);
    i=0;
    do {
        i=v[i];
        j=v[j];
    }
    while (i!=j);
    cout<<i;
    return 0;
}
