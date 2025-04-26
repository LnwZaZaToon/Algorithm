#include<bits/stdc++.h>
using namespace std;


int Calculate(vector<int>&vec , int n, vector<int>&memo){
	if( n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	if(memo[n] != -1){
		return memo[n];
	}
	int count = 0;
	for(int i = 0 ; i< vec.size(); i++){
		int currnum = vec[i];
		count += Calculate(vec,n-currnum,memo);
	}
	memo[n] = count;
	return memo[n];
	
}




int main(){
	vector<int>vec = {1,2,3};
	int n = 4;
	vector<int>temp(n+1,-1);
	cout<<Calculate(vec,n,temp);
	
	
	
	return 0;
}
