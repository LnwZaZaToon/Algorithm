#include<bits/stdc++.h>
using namespace std;

void ShortestPath(vector<vector<char>>& vec , int x , int y,int Dx , int Dy){
//	vector<vector<int>>visited(vec.size() , vector<int>(vec[0].size(),false));
	vector<vector<int>>key(vec.size() , vector<int>(vec[0].size(),INT_MAX));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	
	vector<int>distX = {-1,1,0,0};
	vector<int>distY = {0,0,-1,1};
	
	
	pq.push({0,{x,y}});
	key[x][y] = 0;
	
	while(!pq.empty()){
		int ux = pq.top().second.first;
		int uy = pq.top().second.second;
		pq.pop();
	//	visited[ux][uy] = true;
		

		
		for(int i = 0 ; i<4 ; i++){
			int vx =  ux + distX[i];
			int vy =  uy + distY[i];
			if( vy >= vec[0].size() || vy < 0 || vx >= vec.size() || vx < 0){
				continue;
			}
			char weight = vec[vx][vy];
			if(weight == 'X'){
				continue;
			}
			int vW = (weight =='D')  ? 0 : weight - '0';
			
			if(/*!visited[vx][vy] && */key[vx][vy] > key[ux][uy] + vW){
				key[vx][vy] = key[ux][uy] + vW;
				pq.push({key[vx][vy],{vx,vy}});
			}
		}
		
	}
	for(int i = 0 ; i<key.size() ; i++){
		for(int j = 0 ; j < key[i].size() ; j++){
			cout<<key[i][j] <<" ";
		}
		cout<<endl;
	}
	cout<< key[Dx][Dy];
}




int main(){
	int r , c ; 
	cin>>r >> c;
	int x , y;
	int Dx,Dy;
	vector<vector<char>> vec(r , vector<char>(c));
	for(int i = 0 ; i< r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin>> vec[i][j];
			if(vec[i][j] == 'S') {
				x = i;
				y = j;
			}
			if(vec[i][j] == 'D'){
				Dx = i;
				Dy = j;	
			}
		}
	}
	ShortestPath(vec,x,y,Dx,Dy);
/*	for(int i = 0 ; i < r ; i++){
		for(auto data : vec[i]){
			cout<<data<<" ";
		}
	}*/
//	cout<< x << " "<< y;
	
	return 0;
}
