#include<bits/stdc++.h>
using namespace std;

int TopDown(vector<int>&vec , int n ,vector<int>&memo){
	if(n < 0) return 0;
	if(n==0) return 1;
	if(memo[n] != -1) return memo[n];
	
	int MAXS = 0;	
	for(int i = 1 ; i < vec.size() ; i++){	
		int res = TopDown(vec,n-vec[i],memo);	
		MAXS += res;
	
	}
	return memo[n] = MAXS;
	
	
}




int main(){
	int n , k;
	cin>> n >>k;
	vector<int>vec(k+1);
	vector<int>memo(n+1,-1);
	for(int i = 1 ; i <= k ;i++){
		vec[i] = i;
	}
/*	for(int i = 1 ; i <= k ;i++){
		cout<< vec[i]<<" ";
	}	*/
	cout<<TopDown(vec,n,memo);
	
	return 0;
}
