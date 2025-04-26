#include<iostream>
#include<vector>
using namespace std;

int CrossSum(vector<int>&vec , int low , int high , int mid ){
	int sumL=0 , sumR = 0;
	int MaxL = 0,MaxR = 0;
	for(int i = mid+1 ; i <= high ;i++){
		sumL += vec[i];
		MaxL = max(MaxL,sumL);
	}
	for(int i = mid ; i >= low ; i--){
		sumR += vec[i];
		MaxR = max(MaxR,sumR);
	}
	int sumTotal = MaxL + MaxR;
	return sumTotal;
	
}


int MaximumSub(vector<int>&vec , int low , int high){
	if(low == high ){
		return vec[low];
	}
	int mid = (low+high)/2;
	int left = MaximumSub(vec,low,mid);
	int right = MaximumSub(vec,mid+1,high);
	int cross = CrossSum(vec,low,high,mid);
	
	return max(max(left,right),cross);
	
}





int main(){
	vector<int> vec = { 2,-4 ,1 ,9 ,-6 ,7 ,-3 };
	
	cout<<MaximumSub(vec,0,vec.size()-1);
	
	
	return 0;
}
