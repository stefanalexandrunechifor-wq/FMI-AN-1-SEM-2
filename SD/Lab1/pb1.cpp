#include <iostream>
using namespace std;
int a[100];
int main() {
    int n,q,l,r;
    cin>>n>>q;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (int i = 1; i <= q; i++) {
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
    return 0;
}