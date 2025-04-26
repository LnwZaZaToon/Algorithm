#include<bits/stdc++.h>
using namespace std;



int Djisktra(vector<vector<pair<int,int>>>& vec, int start , int end){
	vector<int>dist(vec.size() , INT_MAX);
	vector<bool>visited(vec.size() , false);
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>  >pq;
	
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for(auto data : vec[u]){
			int v = data.first;
			int vWeight  = data.second;
			int Newweight = dist[u] +vWeight;
			if(!visited[v] && dist[v] > Newweight){
				dist[v] = Newweight;
				pq.push({Newweight,v});
			}
			
		}
	}
	return (dist[end] != INT_MAX)? dist[end]:-1;
}



int main(){
	int c;
	cin >> c;
	vector<int>result;
	for(int i = 0 ; i < c ; i++){
		int n, m , s ,t;
		cin>> n >> m >> s >> t;
		vector<vector<pair<int,int>>>vec(n);
		for(int i = 0 ; i < m  ; i++){
			int a , b , w;
			cin>> a >> b >> w;
			vec[a].push_back({b,w});
			vec[b].push_back({a,w});
		}
		int ans = Djisktra(vec,s,t);
		result.push_back(ans);
	/*	for(int i = 0 ; i < n ; i++){
		//	cout<< i <<": ";
			for(auto data : vec[i]){
			//	cout<< data.first<<" "<< data.second << " ";
			}
			cout<<endl;
		}*/
	}
	for(int i = 0 ; i < result.size() ; i++){
		cout<< result[i]<<endl;
	}
	
	
	return 0;
}
