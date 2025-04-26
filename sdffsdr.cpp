#include<bits/stdc++.h>
using namespace std;
int n = 6;
vector<int>memo (n+1 , -1);
int Topdown(int n ){
	if(n  < 4 ) return n;
	if(memo[n] != -1 )return memo[n];
	return memo[n] = Topdown(n-1)+Topdown(n-2)+Topdown(n-3)-Topdown(n-4);
}

int main(){
	vector<int>dp(n+1, -1);
	int z = n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4 ; i <= n ;  i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3]-dp[i-4];
	}
	cout<<Topdown(z)<<endl;
	cout<<dp[z];
	return 0;
}
