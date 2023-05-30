#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;  // Pair of node and distance

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<pii>>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize distances with infinity
    distances.assign(n, INT_MAX);

    // Set distance of source node to 0
    distances[source] = 0;

    // Push the source node into the priority queue
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        // If the popped distance is already greater than the current distance, skip
        if (dist_u > distances[u])
            continue;

        // Traverse the neighboring nodes of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation: Update distance if a shorter path is found
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    vector<vector<pii>> graph(n);  // Adjacency list representation
    vector<int> distances;  // Vector to store distances from the source node

    // Read the graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // Undirected graph, so add reverse edge as well
    }

    int source;  // Source node for SSSP
    cin >> source;

    // Perform Dijkstra's algorithm
    dijkstra(graph, source, distances);

    // Print the distances from the source node
    for (int i = 0; i < n; i++) {
        cout << "Time taken from source city to city " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << distances[i] << endl;
    }

    return 0;
}
