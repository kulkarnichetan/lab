
#include <iostream>
using namespace std;

// City road network (5 neighbourhoods) -> MST using Prim
int main(){
    const int N = 5;
    int d[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[N], par[N];
    bool in[N];
    for (int i = 0; i < N; ++i) key[i] = 1e9, par[i] = -1, in[i] = false;
    key[0] = 0;

    for (int k = 0; k < N; ++k){
        int u = -1;
        for (int i = 0; i < N; ++i) if (!in[i] && (u == -1 || key[i] < key[u])) u = i;
        in[u] = true;
        for (int v = 0; v < N; ++v) if (d[u][v] && !in[v] && d[u][v] < key[v]) key[v] = d[u][v], par[v] = u;
    }

    int total = 0;
    for (int v = 1; v < N; ++v) total += d[par[v]][v];

    cout << "Minimum total road length: " << total << "\n";
    cout << "Roads:\n";
    for (int v = 1; v < N; ++v) cout << par[v] << " - " << v << " : " << d[par[v]][v] << "\n";
    return 0;
}
