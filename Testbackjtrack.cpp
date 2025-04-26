#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>&vec , vector<int>&result , int start,int count){

		for(int i = 0 ; i < result.size() ; i++){
		cout << result[i]<<" ";
	}
		cout<<endl;
	
	
	for(int i = start ; i < vec.size() ; i++){
		result.push_back(vec[i]);
		count += vec[i];
		backtrack(vec,result,i+1,count);
		count -= vec[i];
		result.pop_back();
	}
	
	return;
}

int main(){
	vector<int>vec = {1,2,3,4};
	vector<int>result;
	backtrack(vec,result,0,0);	
	
	return 0;
}
