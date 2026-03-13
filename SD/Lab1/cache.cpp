#include <iostream>
#include <unordered_map>
using namespace std;
struct cache {
    int cheie;
    int value;
    cache* prev;
    cache* next;
    cache(int c, int v) {
        cheie = c;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
struct List {
    cache* head = nullptr;
    cache* tail = nullptr;
    unordered_map<int, cache*> dictionar;
    //declar capacitatea maxima direct aici sa imi fie mai usor sa lucrez cu ea
    const int k=3;

    void del(int cheie) {
        if (dictionar.count(cheie) == 0) return;
        cache* nodDeSters = dictionar[cheie];

        if (nodDeSters->prev != nullptr) {
            nodDeSters->prev->next = nodDeSters->next;
        } else {
            head = nodDeSters->next;
        }

        if (nodDeSters->next != nullptr) {
            nodDeSters->next->prev = nodDeSters->prev;
        } else {
            tail = nodDeSters->prev;
        }
        dictionar.erase(cheie);
        delete nodDeSters;
    }
    void afis() {
        cache* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->cheie << ":" << temp->value << "] <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void add(int cheie, int valoare) {
        if (dictionar.size()==(k+1)) {
            del(head->cheie);
        }
        if (dictionar.count(cheie) > 0) {
            cache* nodExistent = dictionar[cheie];
            nodExistent->value = valoare;
            if (nodExistent != tail) {
                elem_existent(nodExistent);
            }
            return;
        }
        cache* nodNou = new cache(cheie, valoare);

        if (head == nullptr) {
            head = nodNou;
            tail = nodNou;
        } else {
            tail->next = nodNou;
            nodNou->prev = tail;
            tail = nodNou;
        }
        dictionar[cheie] = nodNou;
    }
    void elem_existent(cache* nod) {
        if (nod->prev != nullptr) {
            nod->prev->next = nod->next;
        } else {
            head = nod->next;
        }
        if (nod->next != nullptr) {
            nod->next->prev = nod->prev;
        }

        tail->next = nod;
        nod->prev = tail;
        nod->next = nullptr;
        tail = nod;
    }
    int get(int cheie) {
        if (dictionar.count(cheie)>0) {
            return dictionar[cheie]->value;
        }
        return -1;

    }
    };
int main() {
List system;
    system.add(1,5);
    system.add(2,4);
    system.add(3,5);
    system.add(2,6);
    cout<<system.get(2)<<endl;
    system.afis();

}
