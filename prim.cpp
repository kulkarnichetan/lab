
#include <iostream>
using namespace std;

// Prim's MST on a small adjacency matrix (0 = no edge)
int main(){
    const int N = 5;
    int w[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[N], parent[N];
    bool inMST[N];
    for (int i = 0; i < N; ++i) key[i] = 1e9, parent[i] = -1, inMST[i] = false;
    key[0] = 0;

    for (int cnt = 0; cnt < N; ++cnt) {
        int u = -1;
        for (int i = 0; i < N; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        inMST[u] = true;

        for (int v = 0; v < N; ++v)
            if (w[u][v] && !inMST[v] && w[u][v] < key[v]) {
                key[v] = w[u][v];
                parent[v] = u;
            }
    }

    int total = 0;
    for (int v = 1; v < N; ++v) total += w[parent[v]][v];

    cout << "MST cost: " << total << "\n";
    cout << "Edges:\n";
    for (int v = 1; v < N; ++v) cout << parent[v] << " - " << v << " : " << w[parent[v]][v] << "\n";
    return 0;
}
