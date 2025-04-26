#include<bits/stdc++.h>
using namespace std;



int BFS(vector<vector<int>>& vec , int start , int end, int n ){
	queue<int>qq;
	vector<bool>visited(n , false);
	
	qq.push(start);
	visited[start] = true;
	vector<int>dist(n+1 , -1);
	dist[start] = 0;
	
	while(!qq.empty()){
		int curr = qq.front();
		qq.pop();
		for(int j = 0 ; j< vec[curr].size() ; j++){
			if(vec[curr][j] == 1 && !visited[j]){
				qq.push(j);
				visited[j] = true;
				dist[j] = dist[curr]+1;
			}
		}
	}
	int minz = INT_MAX;
	for(int i = 0 ; i<dist.size() ; i++){
		cout<<dist[i] << " "<<endl;
	}
	
	cout<<"real: "<<dist[end];
		
}





int main() {
    int n;
    cin >> n;
    vector<vector<int>>vec(101,vector<int>(101 , 0));
    
    for(int i = 0 ;  i<n ; i++){
    	int node;
    	cin>>node;
    	while(true){
    		int edge;
    		cin>>edge;
    		if(edge == 0){
    			break;
			}
			vec[node][edge] = 1;
		}
	}
    int start , end;
    cin>>start >>end;
    
    BFS(vec,start,end,n);
    
   /* for(int i =  0 ; i< vec.size() ; i++){
    	for(int j = 0 ; j< vec[i].size() ; j++){
    		if(vec[i][j] != 0){
    			cout<<"Node:"<<i <<" "<< j <<" "<<endl;
			}
		}
		
	}*/

    return 0;
}

