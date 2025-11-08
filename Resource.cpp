#include <iostream>
#include <vector>
using namespace std;

#define N 6   // number of tasks (vertices)
#define M 4   // number of available resources (colors)

// Check if we can assign color 'c' to vertex 'v'
bool isSafe(int v, const vector<vector<int>>& g, const vector<int>& color, int c) {
    for (int u = 0; u < N; ++u)
        if (g[v][u] && color[u] == c) return false; // neighbor has same color
    return true;
}

// Backtracking utility: try to color vertex 'v'
bool colorUtil(const vector<vector<int>>& g, int m, vector<int>& color, int v) {
    if (v == N) return true;                       // all vertices colored
    for (int c = 1; c <= m; ++c) {                 // try each resource/color
        if (isSafe(v, g, color, c)) {
            color[v] = c;
            if (colorUtil(g, m, color, v + 1)) return true;
            color[v] = 0;                          // backtrack
        }
    }
    return false;
}

void solveColoring(const vector<vector<int>>& g, int m) {
    vector<int> color(N, 0);
    if (!colorUtil(g, m, color, 0)) {
        cout << "No solution exists.\n";
        return;
    }
    cout << "Task Assignments (task -> resource):\n";
    for (int i = 0; i < N; ++i)
        cout << "Task " << (i + 1) << " -> " << color[i] << "\n";
}

int main() {
    // Conflict graph: 1 means tasks conflict (can’t share same resource)
    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {1,0,0,1,0,0},
        {1,0,0,0,1,0},
        {0,1,0,0,0,1},
        {0,0,1,0,0,1},
        {0,0,0,1,1,0}
    };
    solveColoring(graph, M);
    return 0;
}
