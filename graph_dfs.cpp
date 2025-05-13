#include <iostream>
#include <vector>
using namespace std;


void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v; // assuming 0-indexed vertices
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin >> src;
    vector<bool> visited(V, false);
    dfs(src, adj, visited);
    cout << endl;
    return 0;
}
