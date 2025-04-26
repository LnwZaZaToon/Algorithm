#include<bits/stdc++.h>
using namespace std;


int TopDown(vector<vector<int>>&vec , int startx , int starty,int endx,int endy , vector<vector<int>>&memo){
	if(startx == endx && starty == endy ) return vec[endx][endy];
	if(endx < startx || endy < starty) return INT_MAX;
	if(memo[endx][endy] != -1) return memo[endx][endy];
	
	int left = TopDown(vec,startx,starty,endx,endy-1,memo);
	int up = TopDown(vec,startx,starty,endx-1,endy,memo);
	int count =  min(left,up) + vec[endx][endy];

	return memo[endx][endy] = count;
	
	
}


int main(){
	int n , m ;
	cin>> n >> m;
	vector<vector<int>>vec(n,vector<int>(m));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>> vec[i][j];
		}
	}
	int startx , starty;
	cin>> startx >> starty;
	int endx, endy;
	cin>>endx >> endy;
	vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
	cout << TopDown(vec,startx,starty,endx,endy,memo);
	return 0;
}
