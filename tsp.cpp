
#include <iostream>
using namespace std;

// TSP (Branch and Bound) on a 4-city example
const int INF = 1e9;
int n = 4;
int cst[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int best = INF, bestPath[4], curPath[4] = {0, -1, -1, -1};
bool used[4] = {true, false, false, false};

int simpleLB(int cur, int cost){
    int lb = cost;
    for (int i = 0; i < n; ++i){
        if (used[i]) continue;
        int mn = INF;
        for (int j = 0; j < n; ++j) if (i != j && cst[i][j]) mn = min(mn, cst[i][j]);
        if (mn == INF) return INF;
        lb += mn;
    }
    return lb;
}

void dfs(int depth, int cur, int cost){
    int lb = simpleLB(cur, cost);
    if (lb >= best) return;

    if (depth == n){
        if (cst[cur][0]) best = min(best, cost + cst[cur][0]);
        return;
    }

    for (int v = 0; v < n; ++v){
        if (!used[v] && cst[cur][v]){
            used[v] = true;
            curPath[depth] = v;
            dfs(depth + 1, v, cost + cst[cur][v]);
            used[v] = false;
            curPath[depth] = -1;
        }
    }
}

int main(){
    dfs(1, 0, 0);
    cout << "Best tour cost: " << best << "\n";
    return 0;
}
