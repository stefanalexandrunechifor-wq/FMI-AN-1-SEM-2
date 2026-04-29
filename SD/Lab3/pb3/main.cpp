#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;
uint64_t compute_hash(const string& s) {
    const uint64_t P = 31;
    const uint64_t M = (1ULL << 61) - 1;
    uint64_t hash_value = 0;
    for (char c : s) {
        uint64_t char_val = c - 'a' + 1;
        unsigned __int128 next_hash = (unsigned __int128)hash_value * P + char_val;
        //inlocuieste modulo pentru ca e lent
        uint64_t upper_bits = (uint64_t)(next_hash >> 61);
        uint64_t lower_bits = (uint64_t)(next_hash & M);
        hash_value = upper_bits + lower_bits;
        if (hash_value >= M) {
            hash_value -= M;
        }
    }
    return hash_value;
}

int main() {
    string s1 = "programare";
    string s2 = "programator";
    string s3 = "programare";
    string s4 = "eramarporg";
    cout << "Hash '" << s1 << "': " << compute_hash(s1) << "\n";
    cout << "Hash '" << s2 << "': " << compute_hash(s2) << "\n";
    cout << "Hash '" << s3 << "': " << compute_hash(s3) << " (Trebuie sa fie identic cu primul)\n";
    cout << "Hash '" << s4 << "': " << compute_hash(s4) << " (Anagrama, trebuie sa difere)\n";

    return 0;
}