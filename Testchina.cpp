#include<bits/stdc++.h>
using namespace std;

// Function to perform BFS and find if there is a path from source to sink
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}

// Function to find the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int u, v;
    int V = graph.size();
    vector<vector<int>> rGraph(V, vector<int>(V));
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int s, t, l;
        cin >> s >> t >> l;
        graph[s][t] = l;
        graph[t][s] = l; // Assuming the graph is undirected
    }

    int start, end, p;
    cin >> start >> end >> p;

    int max_flow = fordFulkerson(graph, start, end);

    // Calculate the minimum number of trips
    int min_trips = (p + max_flow) / max_flow;

    cout << min_trips << endl;

    return 0;
}
