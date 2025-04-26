#include<bits/stdc++.h>
using namespace std;



int Divide(vector<int>&vec ,int low , int high){
	if(low == high ){
		return low;
	}
	int mid = (low + high )/ 2;
	int left = Divide(vec,low,mid);
	int right = Divide(vec,mid+1 , high);
	
	if(vec[left] != vec[right]){
		return vec[left] != vec[mid] ?left:right;
	}
	else{
		return vec[left] != vec[mid] ?left:right;
	}
	
}



int main(){
	int n;
	cin>>n;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}
	cout<<Divide(vec,0,n-1);
	
	
	
	return 0;
}
