#include <iostream>
#include <vector>
#include <list>
#include <functional>//asta e aici pentru conversii automate fiind o functie de hash predefinita pt ce e la linia 11
using namespace std;
template <typename T>
class ChainingHashTable {
private:
    vector<list<T>> table;
    int current_size;
    int hash_function(T x) {
        return hash<T>{}(x) % table.size();
    }
    void resize() {
        int old_capacity = table.size();
        int new_capacity = old_capacity * 2;
        vector<list<T>> old_table = move(table);
        table = vector<list<T>>(new_capacity);
        current_size = 0;
        for (int i = 0; i < old_capacity; i++) {
            for (const T& element : old_table[i]) {
                insert(element);
            }
        }
    }

public:
    ChainingHashTable(int initial_capacity = 10) {
        table.resize(initial_capacity);
        current_size = 0;
    }
    void insert(T x) {
        if (current_size / (float)table.size() >= 0.7) {
            resize();
        }
        int pos = hash_function(x);
        for (const T& element : table[pos]) {
            if (element == x) {
                return;
            }
        }
        table[pos].push_back(x);
        current_size++;
    }
    bool exists(T x) {
        int pos = hash_function(x);
        for (const T& element : table[pos]) {
            if (element == x) {
                return true;
            }
        }
        return false;
    }
    void erase(T x) {
        int pos = hash_function(x);
        for (auto it = table[pos].begin(); it != table[pos].end(); ++it) {
            if (*it == x) {
                table[pos].erase(it);
                current_size--;
                return;
            }
        }
    }
};

int main() {
    ChainingHashTable<int> mySet(5);
    return 0;
}