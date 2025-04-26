#include<bits/stdc++.h>
using namespace std;


int find(vector<int>&parent , int n){
	if(parent[n] == -1) return n;
	return find(parent , parent[n]);
} 

bool isCycle(vector<int>&parent, int u , int v){
	int x = find(parent , u);
	int y = find(parent , v);
	return (x==y)? true : false;
} 

void Union(vector<int>&parent, int u , int v){
	int x = find(parent , u);
	int y = find(parent , v);
	parent[x] = y;
}




int main(){
	int n , m ;
	cin>> n >> m;
	priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
	for(int i = 0 ; i < m ; i++){
		int x , y , w;
		cin>> x >> y >> w;
		pq.push({w,{x,y}});
	}
	vector<int>parent(n+1,-1);
	int ne = 0;
	int total;
	while(ne < n-1){
		int w = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		cout<< u << "- "<< v <<" "<< w << endl;
		pq.pop();
		if(!isCycle(parent,u,v)){
			ne++;
			Union(parent , u , v);
			total += w-1;
		}
		
	}
	for(int i = 0 ; i < parent.size() ; i++){
		cout<< parent[i]<<" ";
	}
	cout<<endl;
	cout<< total;
	
	return 0;
}
