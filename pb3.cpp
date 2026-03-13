#include <iostream>
using namespace std;
int a[100][100];
int main() {
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    int j=n-1;
    int i=0;
    int ok=0;
    while (i>=0 && j>=0) {
        if (a[i][j]<x)i++;
        else if (a[i][j]>x)j--;
        if (a[i][j]==x) {
            ok++;
            break;
        }
    }
    if (ok!=0)cout<<i<<" "<<j<<endl;
    else cout<<"Nu exista x in matrice!";



    return 0;
}