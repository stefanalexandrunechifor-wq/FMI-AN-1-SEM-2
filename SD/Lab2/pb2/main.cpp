#include <iostream>
using namespace std;
int main() {
    int n,mini=0;
    cin>>n;
    int v[n];
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    int s=0,start=0,maxi=0;
    for (int i=0;i<n;i++) {
        if (mini==0) mini=v[i];
        s=(i-start+1)*mini;
        if (v[i]<mini)mini=v[i];
        if (v[i]>s) {
            start=i;
            mini=v[i];
            s=v[i];
        }
        s=(i-start+1)*mini;
        if (maxi<s) {
            maxi=s;
        }

    }
    cout<<maxi;
    return 0;
}