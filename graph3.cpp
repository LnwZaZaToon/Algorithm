#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& vec, int start, vector<bool>& visited, vector<int>& parent,
 bool &cycleFound) {
    visited[start] = true;
    for (auto data : vec[start]) {
        if (!visited[data]) {
            parent[data] = start;
            DFS(vec, data, visited, parent,cycleFound) ;              
        } else if (parent[start] != data && visited[data]) {  
            cycleFound = true;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n + 1);

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        while (true) {
            int edge;
            cin >> edge;
            if (edge == 0) break;
            vec[node].push_back(edge);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    bool cycleFound = false;
    for (int i = 1; i <= n; i++) {
        if(!visited[i]){
        	DFS(vec, i, visited, parent,cycleFound);
        	if(cycleFound) break;
		}
    }
	cout<< (cycleFound)?"1":"0";

    return 0;
}


/*
6
1 2 3 0
2 1 4 0
3 1 0
4 2 5 0
5 4 6 0
6 5 0
3 6

*/
