#include<bits/stdc++.h>
using namespace std;

int C(int i , int j){
	return 2*i+j;
}

int TopDown(int i , int j,vector<vector<int>>&memo){
	if(i == 0) return 3*j;
	if(j == 0) return 2*i;
	if(memo[i][j] != -1) return memo[i][j];
	int p1 = TopDown(i-1,j,memo)+2;
	int p2 = TopDown(i,j-1,memo)+3;
	int p3 = TopDown(i-1,j-1,memo)+C(i,j);
	return memo[i][j] = min(min(p1,p2),p3);
}


int main(){
	
	int n , m;
	cin>> n >> m;
	vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
	cout<< TopDown(n,m,memo);
	return 0;
}
