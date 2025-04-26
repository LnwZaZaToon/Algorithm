#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent , int i){
	if(parent[i] == -1){
		return i;
	}
	return find(parent , parent[i]);
}

int union1 (vector<int>&parent , int x, int y){
	int xroot = find(parent,x);
	int yroot = find(parent,y);
	parent[xroot] = yroot;
}
int is_cycle(vector<int>&parent ,int u , int v){
	int x = find(parent ,u);
	int y = find(parent,v);
	return (x== y )? true:false;
}


int main(){
	
	int n , m;
	cin>> n >>m;
	priority_queue< pair<int,pair<int,int>> ,vector< pair<int,pair<int,int>>>, greater< pair<int,pair<int,int>>>>pq; 
	vector<int>parent(n+1,-1);
	
	vector<vector<pair<int,int>>>vec (n+1 , vector<pair<int,int>>(m+1));
	for(int i  =1 ; i<= m ; i++){
		int node , edge , weight;
		cin>> node >> edge >> weight;
		vec[node].push_back({edge,weight});
		vec[edge].push_back({node,weight});
		pq.push({weight,{node,edge}});
	}
	int ne = 0;
	int total = 0;
	while(ne < n-1){
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();
		if(!is_cycle(parent,u,v)){
			ne++;
			union1(parent,u,v);
		//	cout<<u<<" "<<v<<" "<<w <<endl;
			total += w-1;
		}
	}
	cout<<total;
	
	
	return  0;
}
