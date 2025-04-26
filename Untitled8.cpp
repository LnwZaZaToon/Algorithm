#include<bits/stdc++.h>
using namespace std;
int C(int i , int j ){
	 return 2*i+j;
}
int P(int i  , int j , vector<vector<int>>&memo ){
	if( i == 0 ) return 3*j;
	if( j == 0 ) return 2*i;
	if( memo[i][j] != -1 )return memo[i][j];
	
	int first = P(i-1,j,memo)+2;
	int second = P(i,j-1,memo)+3;
	int third = P(i-1,j-1,memo)+C(i,j);
	
	return memo[i][j] = min(min(first,second),third);
	
}


int main(){
	int n , m;
	cin>> n >> m;
	vector<vector<int>>memo(n+1 , vector<int>(m+1,0));
//cout<< P(n,m,memo);

	for(int i = 0 ; i <= m ; i++){
		memo[0][i] = 3*i;
	}
	for(int i = 0 ; i <= n ; i++){
		memo[i][0] = 2*i;
	}


	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ;j++){	
			memo[i][j] = min(min(memo[i-1][j]+2 , memo[i][j-1]+3) , memo[i-1][j-1]+(2*i+j));	
		}
	}
	cout<< memo[n][m];
	
	
	return 0;
}
