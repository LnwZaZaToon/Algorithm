#include<bits/stdc++.h>
using namespace std;

void BackTrack(vector<int>&vec , vector<int>&result , int start){
	if(result.size() != 0 ){
		for(int i = 0 ; i < result.size() ; i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	}
	
	for(int i = start ; i < vec.size() ; i++){
		result.push_back(vec[i]);
		BackTrack(vec,result,i+1);
		result.pop_back();
	}
	return;
}

int main(){
	vector<int>vec = { 1,2,3};
	vector<int>result;
	BackTrack(vec,result,0);
	return 0;
}
