#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCrossum(vector<int>&vec , int low , int high,int mid){
	int sum = 0;
	int leftsum = INT_MIN;
	int rightsum = INT_MIN;
	for(int i = mid ; i >= low  ; i-- ){
		sum += vec[i];
		leftsum = max(leftsum,sum);
	}
	sum = 0;
	for(int i = mid+1 ; i <= high  ; i++ ){
		sum += vec[i];
		rightsum = max(rightsum,sum);
	}
	return leftsum+rightsum;
}


int FindMax(vector<int>&vec , int low , int high){
	
	if(low == high){
		return vec[low];
	}
	
	int mid = (low+high)/2;
	int left = FindMax(vec,low,mid);
	int right = FindMax(vec,mid+1,high);
	int crossum = maxCrossum(vec , low ,  high,mid);
	return max(max(left, right), crossum);
	
}




int main(){
	vector<int>vec={2 ,-4, 1, 9 ,-6, 7 ,-3 };
	
/*	int n;
	cin>>n;
	vector<int>vec(n);
	for(int i= 0 ; i< n ;i++){
		cin>>vec[i];
	}*/
	cout<<FindMax(vec,0,vec.size()-1);
	
	
	return 0;
}
