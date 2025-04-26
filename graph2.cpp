#include<bits/stdc++.h>
using namespace std;



int BFS(vector<vector<int>>& vec , int start ){
	queue<int>qq;
	vector<bool>visited(vec.size() , false);
	
	qq.push(start);	
	visited[start] = true;

	while(!qq.empty()){
		int curr = qq.front();
		qq.pop();
		for(int i = 0 ; i<vec[curr].size() ; i++){
			int edges = vec[curr][i];
			if(!visited[edges]){
				qq.push(edges);
				visited[edges] = true;
			}
		}
		//cout<<curr<< " ";	
	}
/*	for(int i = 0 ; i<visited.size() ; i++){
		if(visited[i]){
			cout<<"Node:"<<i << "true"<<" ";
		}
		else{
			cout<<"Node:"<<i << "false"<<" ";
		}
	}*/
	bool flag = false;
	for(int i = 1 ; i< visited.size() ; i++){
		if(visited[i] == false){
			cout<< i <<" ";
			flag = true;
		}
	}
	if(!flag){
		cout<<"0";
	}
	cout<<endl;
	
	
	
}





int main() {
    int n;
    cin >> n;
    vector<vector<int>>vec(n+1);
    for(int i = 1 ; i<=n ;i++ ){
    	int node;
    	cin>>node;
    	while(true){
    		int edge;
    		cin>>edge;
    		if(edge == 0){
    			break;
			}
			vec[node].push_back(edge);
		}
	}
	
	int k;
	cin>>k;
	for(int i = 0 ; i< k ; i++){
		int s;
		cin>>s;
		BFS(vec,s);
		
	}
/*	for(int i = 1 ; i<=n ; i++){
		for(int j = 0 ; j<vec[i].size() ; j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}*/
	


    return 0;
}

