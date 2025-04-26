#include<bits/stdc++.h>
using namespace std;


int main(){
	int n = 4;
	int k;
	cin>> k;
	vector<int>vec(n+1);
	vector<int>weight(n+1);
	for(int i = 1  ; i <= n ; i++){
		cin>>vec[i];
	}
	for(int i = 1  ; i <= n ; i++){
		cin>>weight[i];
	}
	sort(vec.begin()+1 , vec.end());
	sort(weight.begin()+1 , weight.end());
	
	vector<vector<int>>dp(n+1 , vector<int>(k+1,0));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= k ;j ++){
			if(j - weight[i] >= 0){
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-weight[i]] + vec[i]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= k ;j ++){
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<< dp[n][k];
	
	return 0;
}
