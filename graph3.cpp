#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true; // Mark the node in recursion stack

    for (int nextNode : graph[node]) {
        if (!visited[nextNode]) { 
            if (detectCycle(graph, nextNode, visited, recStack)) {
                return true;
            }
        } else if (recStack[nextNode]) {
            return true; // Found a cycle
        }
    }

    recStack[node] = false; // Remove from recursion stack after backtracking
    return false;
}

bool hasCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    vector<bool> recStack(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detectCycle(graph, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; i++) {
        int node;
        cin >> node;
        while (true) {
            int edge;
            cin >> edge;
            if (edge == 0) {
                break;
            }
            graph[node].push_back(edge);
        }
    }

    cout << (hasCycle(graph, n) ? 1 : 0) << endl;

    return 0;
}

