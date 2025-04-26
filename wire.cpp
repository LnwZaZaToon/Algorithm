#include<bits/stdc++.h>
using namespace std;

int TopDown(vector<int>&vec , int k ){
	if( k == 0 ) return 0;
	if(k  < 0 ) return INT_MAX;
	
	int count =  INT_MAX;
	for(int i = 0 ; i < vec.size() ; i++){
		if(k >= vec[i]) {
			int res = TopDown(vec , k-vec[i]);
			if(res != INT_MAX){
				count = min(count , 1+res);
			} 
		}
	}
	return count ;
}



int main(){
	int n = 3 , k ;
	cin >> k;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>> vec[i];
	}
//	cout << TopDown(vec, k);
	
	
	vector<vector<int>>dp(n+1 , vector<int>(k+1 , 0));

	for(int i = 1 ; i<= n  ; i++){
		for(int j = 1 ; j <= k ; j++){
			if( vec[i-1] <= j){
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-vec[i-1]]+1);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
/*	for(int i = 0 ; i <= n ;i++){
		for(int j = 0 ; j <= k ; j++){
			cout<< dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	cout<< dp[n][k];
	return 0;
}
