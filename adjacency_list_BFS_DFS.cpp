#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversal
void BFS(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << "\n";
}

// DFS traversal (recursive)
void DFS(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n); // adjacency list

    cout << "Enter edges (source destination) 0-based indexing:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    // Display adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    int start;
    cout << "\nEnter starting node for traversal: ";
    cin >> start;

    vector<bool> visitedBFS(n, false);
    BFS(start, adj, visitedBFS);

    vector<bool> visitedDFS(n, false);
    cout << "DFS Traversal starting from node " << start << ": ";
    DFS(start, adj, visitedDFS);
    cout << "\n";

    return 0;
}
