#include <iostream>
using namespace std;

#define V 5
int path[V];

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos-1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) return graph[path[pos-1]][path[0]] == 1;
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos+1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(bool graph[V][V]) {
    for (int i = 0; i < V; i++) path[i] = -1;
    path[0] = 0;
    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle\n";
        return false;
    }
    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++) cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    hamCycle(graph);
    return 0;
}

