#include<bits/stdc++.h>
using namespace std;



void BFS(vector<vector<char>>& vec , int x , int y , char target){
	vector<vector<bool>>visited(vec.size() , vector<bool>(vec[0].size()) );
	queue<pair<int,int>> qq;
	
	vector<int>distX = {-1,1,0,0};
	vector<int>distY = {0,0,-1,1};
	
	qq.push({x,y});
	visited[x][y] = true;
	int count = 1;
	
	while(!qq.empty()){
		int ux = qq.front().first;
		int uy = qq.front().second;
		qq.pop();
		for(int i = 0 ; i < 4 ; i++){
			int NewX = ux + distX[i];
			int NewY = uy + distY[i];
						
			if(NewX < 1 || NewY < 1 || NewX >= vec.size() || NewY >=vec[0].size())	continue;
			
			if(!visited[NewX][NewY] && vec[NewX][NewY] == target){
				qq.push({NewX,NewY});
				visited[NewX][NewY] = true;
				count++;
				
			}
		
		}
	}
	cout<< count;
	
}







int main(){
	int row , col ;
	cin>> row >> col;
	vector<vector<char>> vec(row+1 , vector<char>(col+1));
	for(int i = 1 ; i<= row ; i++){
		for(int j = 1 ; j<= col ; j++){
			cin>>vec[i][j];
		}
	}
/*	for(int i = 1 ; i<= row ; i++){
		for(auto data : vec[i]){
			cout<< data <<" ";
		}
		cout<<endl;
	}*/
	
	int x , y;
	cin>> x >> y;
	
	char target = vec[x][y];
	BFS(vec,x,y,target);
	//cout<<target;
	
	
	
	
	
	return 0;
}

