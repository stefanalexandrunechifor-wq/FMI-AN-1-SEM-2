#include <iostream>
#include <vector>
#include <random>

using namespace std;
template<typename Key, typename Value>
struct Entry {
    Key key;
    Value value;
    bool is_empty;
    Entry() {
        is_empty = true;
    }
    Entry(Key key, Value value) : key(key), value(value) {
        is_empty = false;
    }
};

template<typename Key, typename Value>
class hash_t {
private:
    vector<Entry<Key, Value>> table;
    int current_size = 0;
    const int MAX_MUTARI = 50;
    int prim = 8765407;
    int a, b, c, d;
    void genereaza() {
        int dim = table.size();
        a = rand() % dim;
        b = rand() % dim;
        c = rand() % dim;
        d = rand() % dim;
    }

    int h1(Key cheie) {
        int dim = table.size();
        return ((a * cheie + b) % prim) % (dim / 2);
    }
    int h2(Key cheie) {
        int dim = table.size();
        return (dim / 2) + (((c * cheie + d) % prim) % (dim / 2));
    }

public:
    hash_t(int capacitate_initiala) {
        table.resize(capacitate_initiala);
        genereaza();
    }
    void rehash() {
        int old_size = table.size();
        int new_size = old_size * 2;
        vector<Entry<Key, Value>> old_table = move(table);
        table = vector<Entry<Key, Value>>(new_size);
        genereaza();
        current_size = 0;
        for (int i = 0; i < old_size; i++) {
            if (!old_table[i].is_empty) {
                insert(old_table[i].key, old_table[i].value);
            }
        }
    }
    void insert(Key key, Value value) {
        if (current_size >= table.size() / 2) {
            rehash();
        }
        Entry<Key, Value> curent(key, value);
        int pos = h1(curent.key);
        for (int i = 0; i < MAX_MUTARI; i++) {
            if (table[pos].is_empty) {
                table[pos] = curent;
                current_size++;
                return;
            }
           swap(curent, table[pos]);
            if (pos == h1(curent.key)) {
                pos = h2(curent.key);
            } else {
                pos = h1(curent.key);
            }
        }
        rehash();
        insert(curent.key, curent.value);
    }
    bool find(Key key, Value& rezultat) {
        int pos1 = h1(key);
        if (!table[pos1].is_empty && table[pos1].key == key) {
            rezultat = table[pos1].value;
            return true;
        }
        int pos2 = h2(key);
        if (!table[pos2].is_empty && table[pos2].key == key) {
            rezultat = table[pos2].value;
            return true;
        }
        return false;
    }
    bool remove(Key key) {
        int pos1 = h1(key);
        if (!table[pos1].is_empty && table[pos1].key == key) {
            table[pos1].is_empty = true;
            current_size--;
            return true;
        }

        int pos2 = h2(key);
        if (!table[pos2].is_empty && table[pos2].key == key) {
            table[pos2].is_empty = true;
            current_size--;
            return true;
        }

        return false;
    }
};

int main() {
    hash_t<int, string> myHashTable(100);

    return 0;
}