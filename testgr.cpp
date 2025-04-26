#include<bits/stdc++.h>
using namespace std;


int Calculate(vector<int>&vec , int n, vector<int>&memo , int &countrecur){
	if( n == 0){
		return 0;
	}
	if(n < 0){
		return INT_MAX;
	}
	if(memo[n] != -1){
		return memo[n];
	}
	int count = INT_MAX;
	for(int i = 0 ; i< vec.size(); i++){
		countrecur++;
		int temp =  Calculate(vec,n-vec[i],memo,countrecur);
		if(temp != INT_MAX){
			count = min(temp+1,count);
		}
	}
	memo[n] = count;
	return memo[n];
	
}




int main(){
	vector<int>vec = {2,3,5};
	int n = 8;
	int count = 0;
	vector<int>temp(n+1,-1);
	cout<<Calculate(vec,n,temp,count);
	cout<<endl;
	cout<<count;
	
	
	
	
	return 0;
}
