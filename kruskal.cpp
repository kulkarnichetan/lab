#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent;
    DSU(int n){ parent.resize(n); for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x){ return parent[x]==x?x:parent[x]=find(parent[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        parent[b]=a; return true;
    }
};

int main() {
    int n=4; // 4 nodes
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w<b.w; });

    DSU dsu(n);
    int cost=0;
    cout << "MST Edges:\n";
    for(auto e: edges){
        if(dsu.unite(e.u,e.v)){
            cost += e.w;
            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }
    cout << "Total Cost = " << cost << endl;
    return 0;
}

