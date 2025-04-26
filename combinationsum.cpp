#include<iostream>
#include<vector>
using namespace std;


void Comsum(vector<int>&vec , int low,int target ,vector<int>&result){
	if(target == 0) {
		for(int i = 0 ; i< result.size() ; i++){
			cout<< result[i]<<" ";
		}
		cout<<endl;	
	}
	if(target < 0){
		return;
	}
	for(int i = low ; i< vec.size() ; i++){
		result.push_back(vec[i]);
		Comsum(vec,i,target-vec[i],result);
		result.pop_back();
	}
	
}




int main(){
	

	vector<int>vec = { 2,3,6,7};
	vector<int>result;
	int target = 7;
	Comsum(vec,0,target,result);
	
	
	return 0;
}
