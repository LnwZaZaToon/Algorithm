#include<bits/stdc++.h>
using namespace std;
vector<int>weight = {5,4,6,3};
vector<int>value = {10,40,30,50};
int knapSack(int n , int k,vector<vector<int>> &dp ){
	if(n == 0 || k == 0) return 0;
	if(dp[n][k] != -1) return dp[n][k];
	if(weight[n-1]  > k){
			return dp[n][k] = knapSack(n-1,k,dp);
	}
	
	return dp[n][k] = max(knapSack(n-1,k,dp) ,knapSack(n-1,k-weight[n-1],dp)+value[n-1]);
	
}



int main(){
	vector<vector<int>> dp(4+1 , vector<int>(10+1,-1));
	cout << knapSack(4,10,dp);
	
	return 0;
}
