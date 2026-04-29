#include <iostream>
#include<string>
using namespace std;
int main() {
    string cuvant;
    int a[26](0);
    int ramase[26](0);
    string rezultat=" ";
    cin>>cuvant;
    for (int i=0;i<cuvant.length();i++) {
        a[cuvant[i]-'a']++;
        ramase[cuvant[i]-'a']++;
    }
    bool exista[26]={false};
    for (int i = 0; i < cuvant.length(); i++) {
        int idx = cuvant[i] - 'a';
        ramase[idx]--;
        if (a[idx] % 2 == 0) {
            continue;
        }
        if (exista[idx]) {
            continue;
        }

        while (!rezultat.empty() && rezultat.back() > cuvant[i] && ramase[rezultat.back() - 'a'] > 0) {
            exista[rezultat.back() - 'a'] = false;
            rezultat.pop_back();
        }
        rezultat.push_back(cuvant[i]);
        exista[idx] = true;
    }

    cout << rezultat;
}