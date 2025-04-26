#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&vec , int start){
	queue<int>qq;
	vector<int>dist(vec.size(),0);
	
	qq.push(start);
	
	while(!qq.empty()){
		int u = qq.front();
		qq.pop();
		for(auto data : vec[u]){
			qq.push(data);
			dist[data]++;
		}
	}
	
	int MAX = 0;
	for(int i = 1 ; i < dist.size() ; i++){
		MAX = max(MAX , dist[i]);
	}
	for(int i = 1 ; i < dist.size() ; i++){
		if(dist[i] == MAX){
			cout << i << " "; 
		}
	}
}

int main(){
	int n , m , v;
	cin>> n >> m >>v;
	vector<vector<int>>vec(n+1);
	for(int i = 0 ;  i<m ; i++){
		int node , edge;
		cin>> node >> edge;
		vec[node].push_back(edge);
	}	
	BFS(vec,v);
	
	
	return 0;
}
