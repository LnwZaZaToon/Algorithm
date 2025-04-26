#include<bits/stdc++.h>
using namespace std;

void Subset(vector<int>&vec ,int start ,int k ,vector<int>&result){
	
	if(k == 0){
		for(int i = 0 ; i < result.size() ; i++){
			cout<< result[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int i = start ; i < vec.size() ; i++){
		result.push_back(vec[i]);
		Subset(vec,i+1,k-vec[i],result);
		result.pop_back();
	}
	
}




int main(){
	
	int n , k;
	cin>> n >> k;
	vector<int>vec(n);
	vector<int>result;
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}
	Subset(vec,0,k,result);
	
	
	return 0;
}
