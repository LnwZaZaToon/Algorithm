#include<bits/stdc++.h>
using namespace std;


vector<int> ShortestPath(vector<vector<pair<int,int>>>& vec , int start){
	vector<bool>intree(vec.size() , false);
	vector<int>dist(vec.size() , INT_MAX);
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		intree[u] = true;
		for(auto data : vec[u]){
			int v = data.first;
			int vWeight = data.second;
			int newDist = vWeight+dist[u];
			if(!intree[v] && dist[v] > newDist){
				dist[v] = newDist;
				pq.push({dist[v] , v});
			}
		}
	}
/*	for(int i = 1 ; i< dist.size() ; i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;*/
	return dist;
	
}





int main(){
	int f , n;
	cin>>f>>n;
	vector<int>F(f);
	for(int i = 0 ;i < f ; i++){
		cin>>F[i];
	}
	vector<vector<pair<int,int>>>vec(n+1);
	for(int i = 0 ;  i< n ; i++){
		int node ,edge , weight;
		cin>>node>>edge>>weight;
		vec[node].push_back({edge,weight});
		vec[edge].push_back({node,weight});
	}
	vector<int>path(n+1,INT_MAX);
	for(int i = 0 ; i< F.size() ; i++){
		vector<int>dist = ShortestPath(vec,F[i] );
		for(int j = 1 ; j<dist.size() ; j++){
			path[j] = min(path[j] ,dist[j]);
		}
	}
	int Maxz = 0;
	int Node ;
	for(int i = 1 ; i< path.size() ; i++){
		if(Maxz < path[i]){
			Maxz = path[i];
			Node = i;
		}
	}
	cout<<Node;
	
	
	return 0;
}
