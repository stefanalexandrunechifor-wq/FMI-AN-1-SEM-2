#include <iostream>
#include<fstream>
#include<stack>
using namespace std;
int n,m;
int a[1000][1000],v[1000][1000],t[1000];
int calc_aria(int m) {
    stack<int> st;
    int arie_max=0;
    for (int j=0;j<=m;j++) {
        while (!st.empty() && t[j]<t[st.top()]) {
            int inaltime=t[st.top()];
            st.pop();
            int latime;
            if (st.empty()) {
                latime=j;
            }
            else {
                latime=j-st.top()-1;
            }
            arie_max = max(arie_max, inaltime * latime);
        }
        st.push(j);
    }
    return arie_max;

}

int main() {
    ifstream fin("../insert.txt");
    fin>>n>>m;
    int arie=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            fin>>a[i][j];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            if ((i+j)%2==(a[i][j]%2)) {
                v[i][j]=0;
                t[j]++;
            }
            else {
                v[i][j]=1;
                t[j]=0;
            }
        }
        if (arie<calc_aria(m))
            arie=calc_aria(m);
    }
        for(int j = 0; j < m; j++) {
            t[j] = 0;
        }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            if ((i+j)%2!=(a[i][j]%2)) {
                v[i][j]=0;
                t[j]++;
            }
            else {
                v[i][j]=1;
                t[j]=0;
            }
        }
        if (arie<calc_aria(m))
            arie=calc_aria(m);
    }
    cout<<arie;
return 0;
}