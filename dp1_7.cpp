#include<bits/stdc++.h>
using namespace std;

long long TopDown(int n , int m , vector<vector<long long>>&memo){
	if(n == 0 && m == 0) return 1;
	if(n < 0 || m < 0 )return 0;
	if(memo[n][m] != -1 )return memo[n][m];
	long long fromLeft = TopDown(n,m-1,memo);
	long long fromRight = TopDown(n-1 ,m , memo);
	
	long long count = fromLeft+fromRight;
	
	return memo[n][m] = count;
	
	
	
}

int main(){
	int n , m;
	cin>> n >> m;
	n--;
	m--;
	vector<vector<long long >>memo(n+1,vector<long long>(m+1,-1));
	cout<< TopDown(n,m,memo);
	
	
	
	return 0;
}
