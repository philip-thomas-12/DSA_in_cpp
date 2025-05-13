#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Filename: dijkstra_shortest_path.cpp
// Description: Dijkstra's algorithm to find shortest paths from source.

typedef pair<int,int> pii;

void dijkstra(int src, const vector<vector<pii>>& adj, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int V = adj.size();
    dist.assign(V, numeric_limits<int>::max());
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pii>> adj(V);
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // For undirected graph, include reverse:
        // adj[v].push_back({u, w});
    }
    int src;
    cin >> src;
    vector<int> dist;
    dijkstra(src, adj, dist);
    for(int i = 0; i < V; i++) {
        if(dist[i] == numeric_limits<int>::max()) 
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
