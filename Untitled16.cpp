#include<bits/stdc++.h>
using namespace std;
int main(){
	int n  , k;
	cin >> n >> k;
	vector<int>vec(n);
	for(int i = 0 ; i < n; i++){
		cin>>vec[i];
	}
	
	vector<vector<int>>dp (n+1 , vector<int>(k+1 ,0));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= k ;j++){
			if(j >= vec[i-1]){
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-vec[i-1]]+1);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= k ;j++){
			cout<< dp[i][j] <<" ";
		}
		cout<<endl;
	}	
	return 0;
}
