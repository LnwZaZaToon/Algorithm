#include<iostream>
#include<vector>
using namespace std;

int Divide(vector<int>&vec , int target,int low ,int high){	
	if(low == high){
		return (vec[low]==target)?1:0;
	}	
	int mid = (low+high)/2;
	int left = Divide(vec,target,low,mid);
	int right = Divide(vec,target,mid+1,high);
	return left+right;
}





int main(){
	int n,target;
	cin>>n>>target;
	vector<int> vec(n);
	for(int i = 0 ; i<n ; i++){
		cin>>vec[i];
	}
	int ans = Divide(vec,target,0,vec.size()-1);
	cout<<ans;
	
	
	
	
	
	return 0;
}
