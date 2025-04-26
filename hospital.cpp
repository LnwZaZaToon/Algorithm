#include<bits/stdc++.h>
using namespace std;


vector<int> Djistra(vector<vector<pair<int,int>>> &vec  , int start){
	vector<int>dist(vec.size() , INT_MAX);
	vector<int>visited(vec.size() , false);
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq; 
	
	pq.push({0,start});
	dist[start] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for(auto data: vec[u]){
			int v = data.first;
			int vW = data.second;
			int NewDist = dist[u] + vW;
			if(!visited[v] && NewDist < dist[v]){
				dist[v] = NewDist;
				pq.push({NewDist , v});
			}
		}
	}
	

	return dist;
}

int main(){
	int f, n;
	cin>> f >> n;
	vector<int>hospital(f);
	for(int i =  0 ; i < f ; i++ ){
		cin>>hospital[i];
	}
	vector<vector<pair<int,int>>>vec(n+1);
	for(int i =  0 ; i  < n ; i++){
		int x , y ,w;
		cin>> x >> y >> w;
		vec[x].push_back({y,w});
		vec[y].push_back({x,w});
	}
	vector<int>result(n+1, INT_MAX);
	int MAX = INT_MIN;
	int index=  0;
	for(int i = 0 ; i < f ; i++){
	 	vector<int>dist = Djistra(vec , hospital[i]);
	 	for(int i = 1 ; i < dist.size() ;i++){
	 		if(dist[i]<result[i]){
	 			result[i]=dist[i];
			}
		 }
	}
	for(int i =  1 ; i < result.size() ; i++){
	//	cout<<result[i]<<" ";
		if(result[i] > MAX){
			MAX = result[i];
			index = i;
		}
		
	}
	cout<< index;
	
	return 0;
}
/*
2 6
2 5
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10
6 1 10*/
