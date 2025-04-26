#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m ;
	cin>> n >> m;
	vector<vector<int>>vec(n , vector<int>(m));
	for(int i = 0 ; i < n;  i++){
		for(int j = 0 ; j < m ; j++){
			cin>>vec[i][j];
		}
	}
	vector<vector<int>>dp(n , vector<int>(m,0));
	dp[0][0] = vec[0][0];
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + vec[0][j];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + vec[i][0];
    }
	for(int i = 1 ; i <n  ;i++){
		for(int j = 1 ; j < m ; j++){
			dp[i][j] = vec[i][j] + max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	for(int i =0 ; i <n  ;i++){
		for(int j = 0 ; j < m ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl; 
	}
	
	return 0;
}
