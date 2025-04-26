#include<bits/stdc++.h>
using namespace std;
/*
int TopDown( vector<vector<int>>& vec , int n , int k ,vector<vector<int>>& memo){
	if( n == 0 && k == 0) return vec[n][k];
	if( n < 0 || n >= vec.size() ) return INT_MAX;
	if( k < 0 || k >= vec[0].size() ) return INT_MAX;	
	if(memo[n][k] != -1 )return memo[n][k];
	int left = TopDown(vec, n, k-1,memo);
	int up = TopDown(vec,n-1 , k,memo);
	int count = min(left , up);
		
	return memo[n][k] = vec[n][k] + count;
	
}*/


int BottomUp(int n , int k , vector<vector<int>>&vec){
	vector<vector<int>>memo(n+1 , vector<int>(k+1 , 0));
	
	memo[0][0] = vec[0][0];
	for(int i = 1 ; i <= n ; i++ ){
		memo[0][i] = vec[0][i] + memo[0][i-1];
	}
	for(int i = 1 ; i <= n ; i++ ){
		memo[i][0] = vec[i][0] + memo[i-1][0];
	}
	
	for(int i =1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			memo[i][j] = vec[i][j]+min(memo[i-1][j], memo[i][j-1]);
		}
	}
	return memo[n][k];		

}

int main(){
	int n ;
	cin>> n;
	vector<vector<int>>vec(n, vector<int>(n));
	vector<vector<int>>memo(n+1, vector<int>(n+1,-1));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>vec[i][j];
		}
	}

	int s , t;
	cin>> s >> t;
	s--;
	t--;
//	cout<< TopDown(vec,s,t,memo);
	cout<< BottomUp(s,t,vec);
	
	
	return 0;
}
