#include<bits/stdc++.h>
using namespace std;



void Djkistra(vector<vector<pair<int,int>>>& vec , int start , int end){
	vector<bool>intree(vec.size(),false);
	vector<int>dist(vec.size(),INT_MAX);
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	
	pq.push({0,start});
	dist[start] = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		intree[u] = true;
		for(auto data : vec[u]){
			int v = data.first;
			int vWeight = data.second;
			int Newdist = vWeight+dist[u];
			if(!intree[v] && Newdist < dist[v]){
				dist[v] = Newdist;
				pq.push({Newdist,v});
			}
		}
		
	}

	if(dist[end] != INT_MAX){
		cout<<dist[end]<<endl;
	}
	else{
		cout<<"-1";
	}


/*	for(int i = 0 ; i<dist.size() ; i++){
		if(dist[i] != 0 && dist[i] != INT_MAX){
			cout<<dist[i]<<endl;
		}
	}*/
	
}





int main(){
	int c;
	cin>>c;
	for(int i = 0 ; i< c  ;i++){
		int n , m,s,t;
		cin>>n>>m>>s>>t;
		vector<vector<pair<int,int>>>vec(n);
		for(int i = 0 ; i< m ;i++){
			int a , b ,w;
			cin>>a>>b>>w;
			vec[a].push_back({b,w});
			vec[b].push_back({a,w});
		}
		Djkistra(vec,s,t);
	/*	for(int i = 0 ; i< n;  i++){
			cout<< i <<"N :";
			for(auto data : vec[i]){
				cout<< data.first << " ";
			}
			cout<<endl;
		}*/
	}
	
	
	
	return 0;
}
