#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS Traversal
void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (size_t i = 0; i < adj[node].size(); i++) {
            if (adj[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << "\n";
}

// DFS Traversal (recursive)
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (size_t i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] && !visited[i]) {
            DFS(i, adj, visited);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter edges (source destination) 0-based indexing:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
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
