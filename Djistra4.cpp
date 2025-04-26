#include<bits/stdc++.h>
using namespace std;




int Djikstra(vector<vector<pair<int,int>>>& vec , int start ){
	vector<int>dist(vec.size() , INT_MAX);
	vector<bool> intree (vec.size() , false);
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	
	pq.push({0,start});
	dist[start] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		cout << u <<endl;
		pq.pop();
		intree[u] = true;
		
		for(auto data : vec[u]){
			int v = data.first;
			int vWeight = data.second;
			if(intree[v] == false && dist[v] > vWeight){
				dist[v] = vWeight;
				pq.push({dist[v],v});
			}
		}
		
	}
	for(int i = 1 ; i<vec.size() ; i++){
		cout << dist[i] <<" ";
	}
	for(int i = 1 ; i<vec.size() ; i++){
		if(!intree[i]){
			return INT_MAX;
		}
	}
	int total = 0;
	for(int i = 1 ; i< vec.size() ; i++){
		if(dist[i] != 0){
			total += dist[i];
		}
	//	cout<<dist[i]<<" ";
	}
	return total;
	
	
}




int main(){
	int n , m;
	cin>> n >> m;
	vector<vector<pair<int,int>>>vec(n+1);
	for(int i = 0 ; i< m ;i++){
		int node , edge, weight;
		cin>>node>>edge>>weight;
		vec[node].push_back({edge,weight});
	//	vec[edge].push_back({node,weight});
	}
/*	int minZ = INT_MAX;
	for(int i = 1 ; i<= n ;i++){
		int total = Djikstra(vec,i);
		minZ =  min(total , minZ);
	}
	cout<<minZ;*/
	int total = Djikstra(vec,1);
	cout<<total;
/*	for(int i = 1; i<=n ;i++){
		cout<<"Node"<<i<<" : ";
		for(auto data : vec[i]){
			cout<< data.first<<" ";
		}
		cout<<endl;
	}	*/
	
	
	return 0;
}
