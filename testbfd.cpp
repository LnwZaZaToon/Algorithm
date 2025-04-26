#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int>pp;
	vector<vector<int>>vec = {
	{0,1,1,0,0,0},
	{0,0,1,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1},
	{0,0,0,1,0,0},
	{0,0,0,0,0,0},
	};
	
	vector<bool>visited(vec.size(),false);
	int first = 0;
	pp.push(first);
	visited[first] = true;
	
	while(!pp.empty()){
		int curr = pp.front();
		pp.pop();
		cout<<curr<<" ";
		for(int j = 0 ; j< vec.size()  ;j++){
			if(vec[curr][j] == 1 && !visited[j]){
				pp.push(j);
				visited[j] = true;
			}
		}
	}
	
	return 0;
}
