#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int node, weight;
    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &dist) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int u = current.node, d = current.weight;
        if (d > dist[u]) continue;

        for (const Edge &neighbor : graph[u]) {
            int v = neighbor.node, weight = neighbor.weight;
            if (dist[v] > d + weight) {
                dist[v] = d + weight;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    int f, n;
    cin >> f >> n;

    vector<int> hospitals(f);
    for (int i = 0; i < f; i++) {
        cin >> hospitals[i];
        hospitals[i]--; // ??????????? 0-based index
    }

    vector<vector<Edge>> graph(101); // ????????????????????? 100
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        x--, y--; // ??????????? 0-based index
        graph[x].push_back({y, r});
        graph[y].push_back({x, r});
    }

    // ??????????????????????????????????????????????
    vector<int> minDistance(101, INF);
    for (int hospital : hospitals) {
        vector<int> dist(101, INF);
        dijkstra(hospital, graph, dist);
        for (int i = 0; i < 101; i++) {
            minDistance[i] = min(minDistance[i], dist[i]);
        }
    }

    // ??????????????????????????????????????????????????????
    int bestDistrict = -1, maxDist = -1;
    for (int i = 0; i < 101; i++) {
        if (find(hospitals.begin(), hospitals.end(), i) != hospitals.end()) continue; // ?????????????????????????
        if (minDistance[i] == INF) continue; // ?????????????????????????
        if (minDistance[i] > maxDist || (minDistance[i] == maxDist && i < bestDistrict)) {
            maxDist = minDistance[i];
            bestDistrict = i;
        }
    }

    cout << bestDistrict + 1 << endl; // ???????????? 1-based index
    return 0;
}

