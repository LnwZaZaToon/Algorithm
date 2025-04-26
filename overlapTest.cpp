#include<bits/stdc++.h>
using namespace std;

int Top(int n  , vector<int>&memo){
	if(n == 0 || n == 1) return 1;
	if(memo[n]!= -1) return memo[n];
	return memo[n] = Top(n-1,memo) + Top(n-2,memo);
}

int main(){
	int n = 4;
	vector<int>memo(n+1,-1);
	cout << Top(n ,memo)<<endl;
	for(int i = 0 ; i < memo.size() ; i++){
		cout << memo[i] <<" ";
	}
	return 0;
}
