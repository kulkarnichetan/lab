#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n = 5, m = 8; // nodes and edges
    vector<Edge> edges = {
        {0,1,-1}, {0,2,4}, {1,2,3}, {1,3,2},
        {1,4,2}, {3,2,5}, {3,1,1}, {4,3,-3}
    };

    int source = 0;
    vector<int> dist(n, 1e9);
    dist[source] = 0;

    for(int i=0; i<n-1; i++) {
        for(auto e: edges) {
            if(dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    cout << "Shortest distances from source 0:" << endl;
    for(int i=0; i<n; i++) cout << "Node " << i << " : " << dist[i] << endl;

    return 0;
}

