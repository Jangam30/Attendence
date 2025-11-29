#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with minimum distance not yet visited
int minDistance(const vector<int>& dist, const vector<bool>& visited, int n) {
    int minDist = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the path from source to destination
void printPath(const vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

// Dijkstra’s algorithm
void dijkstra(const vector<vector<int>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; // Remaining nodes are unreachable
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path exists from " << src << " to " << dest << ".\n";
    } else {
        cout << "Shortest distance from " << src << " to " << dest << " is: " << dist[dest] << "\n";
        cout << "Path: ";
        printPath(parent, dest);
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter adjacency matrix (enter 0 if no edge exists):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    dijkstra(graph, src, dest);

    return 0;
}
