#include<bits/stdc++.h>
using namespace std;



int Calculate(vector<int>&vec,int n,vector<int>&memo){
	memo[0] = 0;
	for(int i = 1 ; i<= n ; i++){
		for(int j = 0 ; j < vec.size() ; j ++){
			if(i >= vec[j]){
				memo[i] = min(memo[i], 1+memo[i-vec[j]]);
			}
		}
	}
	return memo[n];
	
	
}





int main(){
	int n = 8;
	vector<int>vec = {2,3,5};
	vector<int>memo(n+1,n);
	cout<<Calculate(vec,n,memo);
	
	
	
	
	
	return 0;
}
