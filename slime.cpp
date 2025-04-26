#include<bits/stdc++.h>
using namespace std;

int TopDown(int n ,  int m ,  int k ,vector<vector<int>> & memo){
	if( n < 0 || m < 0 ) return 0;	
	if( n == 0) return 1;
	if( m == 0 ) return 1;
	if(memo[n][m] != -1) return memo[n][m];
	
	
	int left = TopDown(n-1,m-1,k,memo);
	int right = TopDown(n-1,m-k,k,memo);
	int count = left+right;
	return memo[n][m] = count ;
}

int TopDown2(int n ,  int m ,  int k ,vector<vector<int>> & memo){
	if( n < 0 || m < 0 ) return 0;	
	if( n == 0) return 1;
	if( m == 0 ) return 1;
	
	
	int left = TopDown(n-1,m-1,k,memo);
	int right = TopDown(n-1,m-k,k,memo);
	int count = left+right;
	return  count ;
}


int main(){
	int n ;
	int m; 
	cin>> n >> m;
	vector<vector<int>>memo(n+1 , vector<int>(n+1 , -1));
	int ans = TopDown(n,n,m,memo);
	cout<<ans;
	
	
	
	return 0;
}

