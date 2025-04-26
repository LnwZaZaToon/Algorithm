#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}	
	
	vector<vector<int>>dp(n+1 , vector<int>(n+1, 0));
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(j >= i) {
				dp[i][j] = max(dp[i-1][j] , dp[i][j-i] + vec[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}	
	}
	cout << dp[n][n];
	
	return 0;
}
