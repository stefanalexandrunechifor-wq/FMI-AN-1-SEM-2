#include <cmath>
#include <iostream>
using namespace std;
int a[100];
int main() {
    int n,s,st=0,d;
    cin>>n>>s;
    d=n-1;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int mini=9999999999;
    while (st<d) {
        if (mini>abs(a[st]+a[d]-s)) {
            mini=abs(a[st]+a[d]-s);
        }
        if ((a[st]+a[d])>s)
            d--;
        else st++;
    }
    cout<<mini;
    return 0;
}