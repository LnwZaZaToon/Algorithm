#include<bits/stdc++.h>
using namespace std;



int Calculate(vector<int>&vec,int n,vector<int>&memo){
	
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return INT_MAX;
	}
	if(memo[n] != -1){
		return memo[n];
	}
	
	int MinW = INT_MAX;
	for(int i = 0 ; i< vec.size() ; i++){		
		if(n >= vec[i]){
			int data = Calculate(vec,n-vec[i],memo);
			if(data != INT_MAX){
				MinW = min(data+1,MinW);
			}
		}
		
	}
	memo[n] = MinW;
	return memo[n];
	
	
	
}





int main(){
	int n = 8;
	vector<int>vec = {2,3,5};
	vector<int>memo(n+1,-1);
	cout<<Calculate(vec,n,memo);
	
	
	
	
	
	return 0;
}
