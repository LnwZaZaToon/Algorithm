#include<bits/stdc++.h>
using namespace std;

int F(int  n , int k,	vector<int>&memo){
	if(k == 0 || k == 1)return 1;
	if(n == k ) return 1;
	if( memo[n] != -1 ) return memo[n];
	return  memo[n]  = F(n-1,k,memo) + F(n-1,k-2,memo);
}
int main(){
	int n , k;
	cin >> n >> k;
	vector<int>memo(n+1,-1);
//	cout << F(n,k,memo);
	vector<vector<int>> dp(n+1 , vector<int>(k+1,0));
	for(int i = 0 ; i <= n ; i++){
		dp[i][0] = 1;
	}
	for(int i = 0 ; i <= k ; i++){
		dp[0][i] = 1;
	}
	for(int i = 1 ; i<= n ; i++){
		for(int j = 2 ;j<= k ;j++){	
			if(i == j){
				dp[i][j] = 1;
			}
			else if(i >= j){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-2];
			}
		}
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= k ;j++){
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<< dp[n][k];
	
	return 0;
}
