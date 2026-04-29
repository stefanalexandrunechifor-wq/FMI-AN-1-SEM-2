#include <iostream>
using namespace std;
long long cmmdc(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
bool verificare(int x, int y, int z) {
    if ((z>x && z>y)||(z%cmmdc(x,y)!=0)) return{false};
    return{true};
}
//x-cantitatea vasului
//y-vasul in sine
void umplere(int x,int &y) {
    y=x;
}
void golire(int &x) {
    x=0;
}
//x-vasul pe care il torni
//y-vasul in care torni
//z-cantitatea vasului pe care il torni
//w-cantitatea vasului in care torni
void turnare(int &x, int &y, int w) {
    if (y+x>w) {
        x=y+x-w;
        y=w;
    }
    else {
        y=y+x;
        x=0;
    }
}
//T-TURNARE
//R-umplere
//A-golire
int main() {
    int x,y,z;
    int cnt=0;
    cin>>x>>y>>z;
    //x e pt v1
    //y e pt v2
    int v1(0),v2(0);
    if (x==z) {
        umplere(x,v1);
        cout<<'R'<<" ";
        cnt++;
    }
    else if (y==z){
        umplere(y,v2);
        cout<<'R'<<" ";
        cnt++;
    }
    else if (verificare(x,y,z)) {
        v1 = 0;
        v2 = 0;
        cnt = 0;

        while (v1 != z && v2 != z) {
            if (v1 == 0) {
                umplere(x, v1);
                cout << "R ";
                cnt++;
            }
            else if (v2 == y) {
                golire(v2);
                cout << "A ";
                cnt++;
            }
            else {
                turnare(v1, v2, y);
                cout << "T ";
                cnt++;
            }
        }
        cout<< cnt;
    }
}