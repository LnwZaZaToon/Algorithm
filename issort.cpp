#include<iostream>
#include<vector>
using namespace std;

bool isSort(vector<int>&vec,int n){
	if(n == 1){
		return vec[0];
	}
	else if(vec[n-1] > vec[n]){
		return false;
	}
	else{
		return isSort(vec,n-1);
	}
}


int main(){
	vector<int>vec = {2,3,32,78,98,4};
	if(isSort(vec,vec.size()-1)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	
	
	
	return 0;
}
