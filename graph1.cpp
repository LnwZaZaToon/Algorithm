#include<bits/stdc++.h>
using namespace std;

void BFS ( vector<vector<int>>&vec , int start, int end){
	queue<int>qq;
	vector<bool>visited(vec.size() , false);
	qq.push(start);
	visited[start]  = true;
	vector<int>parent(vec.size(),-1);
	
	while(!qq.empty()){
		int curr = qq.front();
		cout << curr <<" ";
		qq.pop();
		for(auto data :  vec[curr]){
			if(!visited[data]){
				qq.push(data);
				visited[data] = true;
				parent[data] = curr;
			}
		}
	//	cout<< curr<< " ";
	}
/*	cout<<endl;
	for(int i = 0 ; i< parent.size() ; i++){
		cout<<parent[i]<<" ";
	}
	cout<<endl;*/
	int count = 0;
	int  i= end;
	int node = parent[i];
	while( node != -1){
		count++;
		node = parent[node];

	}
	cout << count;
	
	
	
}

void DFS(vector<vector<int>>&vec , int start , vector<bool> & visited ){
	cout<<start<< " ";
	visited[start]  = true;
	for(auto data : vec[start]){
		if(!visited[data]){
			DFS(vec, data , visited);
		}
	}
}





int main(){
	int n  ;
	cin >> n;
/*	vector<vector<int>>vec;
	vec.resize(n+1);*/
	vector<vector<int>>vec(n);
	int count = 0;
	for(int i = 0 ; i< n ; i++){
		int node, edge= INT_MAX;
		cin>>node;
		while(edge != -1){
			int edge;
			cin>>edge;
			if(edge == -1 ) break;
			vec[node].push_back(edge);
			vec[edge].push_back(node);
		}
		
		
	}
	int start , end;
	cin>>start >> end;
	BFS(vec,start,end);
//	cout<<endl;
//	vector<bool> visited(n , false);
//	DFS(vec, 1 , visited);
	
/*	for(int i = 1 ; i<= n ; i++){
		cout<<i << ": ";
		for(auto data : vec[i]){
			cout<<data<<" ";
		}
		cout<<endl;
	}*/

	return 0;
}
/*
5
6
1 2
2 3
3 4
4 5
4 6
5 2*/

/*

5 6
0 1
0 2
2 3
1 3
3 4
4 5

*/

