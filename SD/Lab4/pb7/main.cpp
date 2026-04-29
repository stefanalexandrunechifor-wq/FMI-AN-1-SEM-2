#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const int INFINIT = 1e9;
struct Muchie {
    int destinatie;
    int cost;
};
struct NodDistanta {
    int nume_nod;
    int distanta_acumulata;
    bool operator>(const NodDistanta& altul) const {
        return distanta_acumulata > altul.distanta_acumulata;
    }
};
void ruleaza_dijkstra(int nod_start, int nr_noduri, const vector<vector<Muchie>>& lista_adiacenta, vector<int>& distante_minime) {
    distante_minime.assign(nr_noduri + 1, INFINIT);
    distante_minime[nod_start] = 0;
    priority_queue<NodDistanta, vector<NodDistanta>, greater<NodDistanta>> coada_prioritate;
    coada_prioritate.push({nod_start, 0});
    while (!coada_prioritate.empty()) {
        int nod_curent = coada_prioritate.top().nume_nod;
        int dist_curenta = coada_prioritate.top().distanta_acumulata;
        coada_prioritate.pop();
        if (dist_curenta > distante_minime[nod_curent]) {
            continue;
        }
        for (const auto& muchie : lista_adiacenta[nod_curent]) {
            int vecin = muchie.destinatie;
            int cost_arc = muchie.cost;
            if (distante_minime[nod_curent] + cost_arc < distante_minime[vecin]) {
                distante_minime[vecin] = distante_minime[nod_curent] + cost_arc;
                coada_prioritate.push({vecin, distante_minime[vecin]});
            }
        }
    }
}

int main() {
    ifstream fin("dijkstra.in");
    ofstream fout("dijkstra.out");
    int N, M;
    if (!(fin >> N >> M)) return 0;
    vector<vector<Muchie>> graf(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        fin >> u >> v >> c;
        graf[u].push_back({v, c});
    }
    vector<int> rezultate_distante;
    ruleaza_dijkstra(1, N, graf, rezultate_distante);
    for (int i = 2; i <= N; ++i) {
        if (rezultate_distante[i] == INFINIT) {
            fout << 0 << " ";
        } else {
            fout << rezultate_distante[i] << " ";
        }
    }
    fin.close();
    fout.close();

    return 0;
}