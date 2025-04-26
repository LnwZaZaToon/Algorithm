#include<bits/stdc++.h>
using namespace std;

long long F(long long n , long long k ,vector<vector<long long>> &memo){
	if( k == 0 || k == 1) return 1 ;
	if( n == k ) return 1;
	if(memo[n][k] != -1) return memo[n][k];
	
	
	return memo[n][k] = F(n-1,k,memo) + F(n-1,k-2,memo);
	
}



int main(){
	long long n , k;
	cin>> n >> k;
	vector<vector<long long>>memo(n+1,vector<long long>(k+1,-1));
	cout << F(n,k,memo);
	
	return 0;
}
