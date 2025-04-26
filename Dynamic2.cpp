#include<bits/stdc++.h>
using namespace std;


int Fac(int n,vector<int>&memo ){
	if( n== 0 || n == 1) return 1;
	if(memo[n] != -1) return memo[n];
	return memo[n] = Fac(n-1,memo) * n;

}


int C(int n , int k ,vector<int>&memo){
	int ratio = n-k;
	return Fac(n,memo) / (Fac(ratio,memo)*Fac(k,memo));
}


int main(){
	int n , k ;
	cin>>n >> k;
	vector<int>memo(n+1,-1);
	cout << C(n,k,memo);
	
	
	return 0;
}
