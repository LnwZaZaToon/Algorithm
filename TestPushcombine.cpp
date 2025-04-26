#include<bits/stdc++.h>
using namespace std;

void Combination(vector<int>&vec , int start ,  int end , vector<int>&result){
	
	if(start == end ){
		for(int i  = 0 ; i< result.size() ; i++){
			cout<< result[i] << " ";
		}
		cout<<endl;
	}
	
	
	for(int i = start ; i < end ;i++){
		result.push_back(vec[i]);
		Combination(vec,start+1,end,result);
		result.pop_back();
	}
	
}



int main(){
	vector<int>vec = {1,2,3};	
	vector<int>result;
	Combination(vec,0,vec.size() , result);
	
	return 0;
}
