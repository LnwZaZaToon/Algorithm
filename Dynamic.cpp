#include<bits/stdc++.h>
using namespace std;

int C(int n,int k ,vector<vector<int>>&memo){
	if(n == k ) return 1;
	if(k == 0) return 1;
	if(memo[n][k] != -1) return memo[n][k];
	
	memo[n][k] = C(n-1,k-1,memo) + C(n-1,k,memo);
	return memo[n][k];
	
}

int main(){
	int n, k;
	cin>> n >> k;
	vector<vector<int>>memo(n+1,vector<int>(k+1,-1));
	cout<< C(n,k,memo)<<endl;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0; j <= k ; j++){
			cout << memo[i][j]<<" ";
		}
		cout<<endl;
	}
	/*
		vector<vector<int>>memo(n+1,vector<int>(k+1,0));
		for(int i = 0 ; i <= n ; i++){
			memo[i][0] = 1;
		}
		for(int i = 0 ; i <= k ; i++){
			memo[0][i] = 1;
		}
		for(int i =  1 ; i <= n ; i++){
			for(int j = 1 ; j <= k ; j++){
				if(i == j){
					memo[i][j] = 1;
				}
				else{
					memo[i][j] = memo[i-1][j-1] + memo[i-1][j]; 
				}
			}
		}
		for(int i =  0 ; i <= n ; i++){
			for(int j = 0 ; j <= k ; j++){
				cout<< memo[i][j]<<" ";
			}
			cout<<endl;
		}*/
}
