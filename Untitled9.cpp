#include<bits/stdc++.h>
using namespace std;


int TopDown(vector<vector<int>>&vec , int x1 , int x2 , int y1 , int y2 , vector<vector<int>>&memo ){
	if(x1 == y1 && x2 == y2 ) return vec[y1][y2];
	if(y1 < x1 || y2 < x2) return INT_MAX;
	if(memo[y1][y2] != -1) return memo[y1][y2];
	int up = TopDown(vec,x1,x2,y1-1,y2,memo);
	int left = TopDown(vec,x1,x2,y1,y2-1,memo);
	
	int count = min(up , left) + vec[y1][y2];
	return memo[y1][y2] = count;
	
}


int main(){
	int n,m ;
	cin>> n >> m;
	vector<vector<int>>vec(n , vector<int>(m));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>vec[i][j];
		}
	}
	int x1 , x2 , y1 , y2;
	cin >> x1 >> x2 >> y1 >> y2;
	vector<vector<int>>memo(n+1 ,vector<int>(m+1,-1));
	cout << TopDown(vec,x1,x2,y1,y2,memo);
	return 0;
}
