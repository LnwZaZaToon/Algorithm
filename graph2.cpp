#include<bits/stdc++.h>
using namespace std;


void BFS(vector<vector<int>>& vec, int start){
	int n = vec.size();
	queue<int>qq;
	vector<bool>visited(n , false);
	
	qq.push(start);
	visited[start]  = true;
	
	while(!qq.empty()){
		int curr = qq.front();
		qq.pop();
		//cout<< curr;
		
		for(auto data : vec[curr]){
			if(!visited[data]){
				qq.push(data);
				visited[data] = true;
			}
		}
	}
	bool flag = false;
	for(int i = 0 ; i<visited.size() ; i++){
		if(visited[i] !=  true){
			cout<<i+1<< " ";
			flag = true;
		}
	}
	
	if(!flag){
		cout<<"0";
	}
	
	cout<<endl;
	
	
	
}






int main(){
	int n ;
	cin>>n;
	vector<vector<int>>vec(n);
	for(int i = 0 ; i< n ; i++){
		int node;
		cin>>node;
		while(true){
			int edge;
			cin>>edge;
			if(edge == 0 )break;
			vec[node-1].push_back(edge-1);
		}
	}
	int k ;
	cin>> k;
	for(int i = 0 ; i< k ; i++ ){
		int s;
		cin>>s;
		BFS(vec,s-1);
	}
	
	
	
/*	for(int i = 0 ; i< n ; i++){
		cout<< i <<" ";
		for(auto data : vec[i]){
			cout<<data <<" ";
		}
		cout<<endl;
	}*/
	
	return 0;
}
