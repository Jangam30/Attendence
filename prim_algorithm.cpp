#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Edge: (weight, vertex)
typedef pair<int, int> Edge;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<Edge>> adj(n); // adjacency list

    cout << "Enter edges in format: source destination weight (0-based index)\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // undirected graph
    }

    vector<int> key(n, INT_MAX);      // min weight to reach vertex
    vector<int> parent(n, -1);        // store MST
    vector<bool> inMST(n, false);     // visited vertices

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // min-heap: (weight, vertex)

    key[0] = 0;
    pq.push({0, 0}); // start from vertex 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &[weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "  Weight: " << key[i] << "\n";
        totalWeight += key[i];
    }
    cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}
