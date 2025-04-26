#include<bits/stdc++.h>
using namespace std;


void Backtrack(vector<int>&vec , int start , int k ,vector<int>&result ){
	if(k == 0 ){
		for(int i = 0 ; i < result.size() ; i++){
			cout<< result[i]<<" ";	
		}
		cout<<endl;
		return;
	}
	for(int i = start ; i < vec.size() ; i++){
		if(k>=vec[i]){
			result.push_back(vec[i]);
			Backtrack(vec,i+1,k-vec[i],result);
			result.pop_back();			
		}
	}
	
}

/*
4 12
25 10 9 2 1
*/


int main(){
	
	int n = 5, k;
	cin>> k;
	vector<int>vec(n);
	vector<int>result;
	for(int i =  0 ; i  < n ; i++){
		cin>>vec[i];
	}
//	sort(vec.begin() , vec.end());
	Backtrack(vec,0,k,result);
	
	
	return 0;
}
