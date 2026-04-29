#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int vedeta=0;
    for (int i=1;i<n;i++) {
        if (knows(vedeta,i)) {
            vedeta=i;
        }
    }
    //caz in care nu este nicio vedeta
    for (int i=0;i<n;i++) {
        if (vedeta!=i) {
            if (knows(vedeta,i)) {
                vedeta=-1;
            }
            else if (!knows(i,vedeta)) {
                vedeta=-1;
            }
        }
        if (vedeta==-1) break;
    }
    if (vedeta!=-1) cout<<vedeta;
    else cout<<"Nu exista nicio vedeta!";
    return 0;
}