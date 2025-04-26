#include<iostream>
#include<vector>
using namespace std;

bool FindSum(vector<int>&vec,int k,vector<int>&temp){
	if(temp[k] != -1){
		return temp[k];
	}
	if( k == 0){
		return true;
	}
	if( k < 0){
		return false;
	}
	for(int i = 0 ; i< vec.size() ; i++){
		int value = k-vec[i];
		if(FindSum(vec,value,temp)){
			temp[k] = true;
			return temp[k];
		}
	}
	temp[k] = false;
	return temp[k];
}




int main(){
	int n ,k;
	cin>>n>>k;
	vector<int>vec(n);
	vector<int>temp(k+1,-1);
	for(int i = 0  ; i< vec.size() ; i++){
		cin>>vec[i];
	}
	if(FindSum(vec,k,temp)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}

	

}
