#include<bits/stdc++.h>
using namespace std;

bool TopDown(vector<int>&vec,int j  , int k,vector<int>&memo){
	if(k == 0) return true;
	if(k < 0 ) return false;
	if(memo[k] != -1) return memo[k];

	for(int i = j ; i < vec.size() ; i++){
		int data = k-vec[i];
		int res = TopDown(vec,i+1,k-vec[i],memo);
		if(res){
			return memo[k] = true;
		}
	}

	return memo[k] = false;
	
}


int main(){
	int n, k;
	cin>> n >> k;
	vector<int>vec(n) ;
	vector<int>memo(k+1,-1);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}
	if(TopDown(vec,0,k,memo)){
		cout<<"T";
	}
	else{
		cout<<"F";
	}
	
	
	
	
	return 0;
}
