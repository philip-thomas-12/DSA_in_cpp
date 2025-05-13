#include <iostream>
#include <vector>
#include <queue>
using namespace std;


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
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}

