#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin>> n;
	vector<int>dp(n+1,0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3 ; i <= n ;i++){
		dp[i] = dp[i-1]+dp[i-2]-dp[i-3];
	}
	for(int i = 0 ; i < dp.size() ; i++){
		cout << dp[i] <<" ";
	}
	cout<<dp[n];
	
	return 0;
}
