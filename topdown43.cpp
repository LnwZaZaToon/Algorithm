#include<bits/stdc++.h>
using namespace std;

int TopDown(int n ,vector<int>&memo){
	if(n == 1 || n == 2) return 1;
	if(memo[n] != -1) return memo[n];
	return memo[n] = 3*TopDown(n-1,memo)+ TopDown(n-2,memo);
}



int main(){
	int n;
	cin>>n;
	vector<int>memo(n+1,-1);
	cout<< TopDown(n,memo);
	
	return 0;
}
