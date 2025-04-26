#include<bits/stdc++.h>
using namespace std;


bool TopDown(vector<int>&vec,int j , int k , vector<vector<bool>>&memo){
	if( k == 0 ) return true;
	if( j >= vec.size())return false;
	if( k  < 0 ) return false;
	if( memo[j][k] != false) return memo[j][k];
	int count = 0;
	for(int i=j ; i < vec.size() ; i++){
		if(k >= vec[i]){
			bool res = TopDown( vec, i+1 , k - vec[i], memo);
			if(res){
				memo[j][k] = true;
				return true;
			}
		}
	}
	return memo[j][k] = false;
	
}



int main(){
	vector<int>vec = {3,4,5,2};
	int k = 50;
	vector<vector<bool>>memo(vec.size()+1 , vector<bool>(k+1,false));
	bool ans = TopDown(vec,0,k ,memo);
	if(ans ){
		cout<<" 1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
