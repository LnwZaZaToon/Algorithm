#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&vec ,int start , int end){
	vector<bool>visited(vec.size() , false);
	vector<int>parent(vec.size() , -1);
	queue<int>qq;
	
	qq.push(start);
	visited[start] = true;
	
	while(!qq.empty()){
		int curr = qq.front();
		qq.pop();
		//cout<< curr<<" ";
		for(auto data : vec[curr]){
			if(!visited[data]){
				qq.push(data);
				visited[data] = true;
				parent[data] = curr;
			}
		}
	}
	int count = 0;
	int node = parent[end];
	while(node != -1){
		count++;
		node = parent[node];
	}
	cout<< count;
	
	
}


int main(){
	int n;
	cin>> n;
	vector<vector<int>>vec(n+1);
	for(int i = 0 ; i< n ;i++){
		int node;
		cin>> node;
		while(true){
			int edge;
			cin>>edge;
			if(edge == 0) break;
			vec[node].push_back(edge);
		}
	}
	int start , end;
	cin>> start >> end;
	BFS(vec,start,end);
/*	for(int i = 1 ; i < vec.size() ; i++){
		cout<< i <<" : ";
		for(auto data : vec[i]){
			cout<< data <<" ";
		}
		cout<<endl;
	}*/
	
	
	
	return 0;
}
