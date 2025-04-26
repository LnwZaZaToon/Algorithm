#include<bits/stdc++.h>
using namespace std;


int Prims(vector<vector<pair<int,int>>>&vec , int start , int end,int people){
	vector<int>visited(vec.size() , false);
	vector<int>dist(vec.size() , INT_MIN);
	vector<int>parent(vec.size() , -1);
	priority_queue< pair<int,int>  > pq;
	
	pq.push({0,start});
	dist[start] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for(auto data: vec[u]){
			int v = data.first;
			int vWeight = data.second;
			if(!visited[v] &&  dist[v] < vWeight){
				dist[v] = vWeight;
				pq.push({vWeight,v});
				parent[v] = u;
			}
		}
	}
	int count = 0;
	int MIN = INT_MAX;
	int node = parent[end];
	while(node != -1 ){;
		if(node != start){
			MIN = min(MIN , dist[node]);
		}
		node = parent[node];	
	}
	//cout<<MIN;
	//cout<<people <<" ";
	while(people > 0){
		count++;
		people = (people-MIN)+1;
		//cout<<people<<" ";
	}
	cout << count;
	
}



int main(){
	
	int n ,  k;
	cin>> n >> k;
	
	vector<vector<pair<int,int>>>vec(n+1);
	for(int i = 0 ; i < k ; i++){
		int x , y ,w;
		cin>> x >> y >> w;
		vec[x].push_back({y,w});
		vec[y].push_back({x,w});
	}
	int start ,end, people;
	cin>> start >> end>> people;
	
	Prims(vec,start,end,people);
	
	
	
	
	return 0;
}
