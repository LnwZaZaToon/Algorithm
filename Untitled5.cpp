#include<bits/stdc++.h>
using namespace std;


void DFS(vector<vector<int>>&vec, int start,vector<bool>&visited,vector<int>&parent,bool &cycleFound){
	cout << start <<" ";
	visited[start] = true;
	
	for(auto data: vec[start]){
		if(!visited[data]){
			parent[data] = start;
			DFS(vec,data,visited,parent,cycleFound);
		}
		else if( visited[data] && parent[start] != data && parent[start] != -1 ){
			cycleFound = true;
			return;
		}
	}
	return;
}



int main(){
	int n ;
	cin >> n;
	vector<vector<int>>vec(n+1);
	for(int i = 0 ; i < n; i++){
		int node;
		cin >> node;
		while(true){
			int edge;
			cin>>edge;
			if(edge == 0 )break;
			vec[node].push_back(edge);
		}
		
	}
	
	for(int i = 1 ; i <= n;i++ ){
		cout<<"Node:"<<i<<" ";
		for(auto data: vec[i]){
			cout<< data << " ";
		}
		cout<<endl;
	}
	vector<bool>visited(n+1,false);
	vector<int>parent(n+1,-1);
	bool cycleFound = false;
	DFS(vec,1,visited,parent,cycleFound);
	if(cycleFound){
		cout<<"Found";
	}
	else{
		cout<<"not Found";
	}
	return 0;
}
