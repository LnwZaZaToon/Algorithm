#include <bits/stdc++.h>
using namespace std;



int BFS(vector<vector<int>>&vec , int start , int m){
	vector<bool>visited(vec.size() , false);
	vector<int>dist(vec.size() , 0);
	queue<int>qq;
	
	qq.push(start);
	visited[start]  = true;
	
	while(!qq.empty()){
		int curr = qq.front();
	//	cout<<curr<<" ";
		qq.pop();
		for(auto data: vec[curr]){
			if(!visited[data]){
				qq.push(data);
				dist[data] = dist[curr]+1;
				visited[data] = true;
			}
		}
	}
	int count = 0;
	for(int i = 1 ; i< dist.size() ; i++){
		if(dist[i] > m ){
			count++;
		}
	}
	return count;
}



int main(){
	int n;
	cin>>n;
	vector<vector<int>>vec(n+1);
	int node = INT_MAX, edge = INT_MAX;
	while(true){
		int node, edge;
		cin>>node >> edge;
		if(node == 0 && edge == 0) break;
		vec[node].push_back(edge);	
	}
/*	
	for(int i = 1 ; i <= n ; i++){
		cout<<"Node:"<< i <<" = ";
		for(auto data : vec[i]){
			cout<<data<<" ";
		}
		cout<<endl;
	}*/
	int k , m;
	cin>> k >> m;	
	
	cout<<	BFS(vec,k,m);
	
	
	
	
	return 0;
}


/*

7
1 2
1 4
1 5
2 3
2 5
3 1
3 6
3 7
4 5
5 4
6 5
6 7
0 0
1 2


*/
