#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , k ;
	cin>> n >> k ;
	vector<int>value(n);
	vector<int>weight(n);
	
	for(int i = 0 ; i < n ; i++){
		cin>> value[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>> weight[i];
	}
	
	vector<vector<int>>dp(n+1 , vector<int>(k+1 , 0));
	
	for(int i = 1 ; i <= n;  i++){
		for(int j = 1 ; j <= k ; j++){
			if(weight[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-weight[i-1]]+value[i-1]);
			}
		}
	}
	for(int i = 1 ; i <= n;  i++){
		for(int j = 1 ; j <= k ; j++){
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	return 0;
}

/*

7 15
3 4 5 25 20 12 11
2 3 4 15 10 8 7


*/
