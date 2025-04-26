#include<bits/stdc++.h>
using namespace std;


int TopDown(vector<int>&vec,int n,vector<int>&memo){
	if(n == 0) return 0;
	if(n < 0) return INT_MIN;
	if(memo[n] != -1) return memo[n];
	
	int count = INT_MIN;
	
	for(int i = 1 ; i <= n ; i++){
			int data = vec[i-1] + TopDown(vec,n-i,memo);
			count = max(data,count);
		}
	return memo[n] = count;
	
}


int main(){
	int n;
	cin>> n;
	vector<int>vec(n);
	vector<int>memo(n+1,-1);
	for(int i = 0; i < n ;i++){
		cin>>vec[i];
	}
	cout<< TopDown(vec,n,memo);
	return 0;
}
