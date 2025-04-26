#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
	int des;
	int weight;
	Graph(int d , int w){
		this->des = d;
		this->weight = w;
	}
};



/*void AddEdges(vector<vector<Graph>>&vec,int start ,int des , int weight){
	vec[start].push_back(Graph(des,weight));
	
}*/

void AddEdges(vector<vector<Graph>>&vec,int start ,int des , int weight){
	vec[start].push_back({des,weight});
	
}
void PrintGraph(vector<vector<Graph>>&vec){
	for(int i = 0 ; i < vec.size() ; i++){
		for(int j = 0 ; j <vec[i].size() ; j++){
			cout<< "Node: " << i << " "<< "des:"<< vec[i][j].des <<" "<< "weight: "<< vec[i][j].weight<<endl;
		}
	}
}

int ShortestPath(vector<vector<Graph>>&vec , int k ){
	int n = vec.size();
	vector<int>dist(n,INT_MAX);
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

	pq.push({0,k});
	dist[k] = 0;
	
	while(!pq.empty()){
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		 if (cost > dist[node]) continue;
		for(int i = 0 ; i<vec[node].size() ; i++){
			int newdist = cost + vec[node][i].weight;
			if(newdist < dist[vec[node][i].des])
				dist[vec[node][i].des] = newdist;
				pq.push({newdist,vec[node][i].des});
			}
		}
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
    
    int maxz = INT_MIN;
    for(int i = 0 ; i < dist.size() ; i++){
		if(dist[i] != INT_MAX){
			maxz = max(dist[i],maxz);    	
		}
	}
	return (maxz != INT_MIN)? maxz : -1;
}
	





int main(){
	int n = 2;
	int k = 1;
	vector<vector<Graph>> vec(n);
	AddEdges(vec,1,2,1);
	PrintGraph(vec);
	cout<<ShortestPath(vec,k);
	return 0;
}
