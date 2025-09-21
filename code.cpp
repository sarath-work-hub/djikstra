
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <stack>

using namespace std;

struct Edge {
    int to;
    int weight;
};

class Graph {
    unordered_map<int, vector<Edge>> adjList;

public:
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // remove if directed graph
    }

    void dijkstra(int start, int end) {
        unordered_map<int, int> dist;
        unordered_map<int, int> parent;
        for (auto &pair : adjList) {
            dist[pair.first] = numeric_limits<int>::max();
        }

        dist[start] = 0;

        // Min-heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &edge : adjList[u]) {
                int v = edge.to;
                int w = edge.weight;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[end] == numeric_limits<int>::max()) {
            cout << "No path found from " << start << " to " << end << endl;
            return;
        }

        cout << "Shortest path cost from " << start << " to " << end << ": " << dist[end] << endl;

        // Reconstruct path
        stack<int> path;
        int curr = end;
        while (curr != start) {
            path.push(curr);
            curr = parent[curr];
        }
        path.push(start);

        cout << "Path: ";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    // Hardcoded graph
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 5, 3);
    g.addEdge(5, 4, 4);
    g.addEdge(4, 6, 11);

    int start, end;
    cout << "Enter starting node: ";
    cin >> start;
    cout << "Enter ending node: ";
    cin >> end;

    g.dijkstra(start, end);

    return 0;
}
