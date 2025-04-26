#include<iostream>
#include<vector>
using namespace std;

int BSearch1(vector<int>&vec , int target , int left ,int right){
	if(left>right){
		return -1;
	}
	int mid = (left+right)/2;
	if(vec[mid] == target){
		int index = BSearch1(vec,target,left,mid-1);
		return (index == -1 )? mid : index;
	}
	else if(vec[mid] > target){
		return BSearch1(vec,target,left,mid-1);
	}
	else{
		return BSearch1(vec,target,mid+1,right);
	}
}

int BSearch2(vector<int>&vec , int target , int left ,int right){
	if(left>right){
		return -1;
	}
	int mid = (left+right)/2;
	if(vec[mid] == target){
		int index = BSearch2(vec,target,mid+1,right);
		return (index == -1 )? mid : index;
	}
	else if(vec[mid] > target){
		return BSearch2(vec,target,left,mid-1);
	}
	else{
		return BSearch2(vec,target,mid+1,right);
	}
}



int main(){
	vector<int>vec {2,5,5,5,5,6,6,8,8,8,9,9};
	int target =20;
	int a = BSearch1(vec,target,0,vec.size()-1);
	int b = BSearch2(vec,target,0,vec.size()-1);
	cout<< b-a+1;
	
	
	
	return 0;
}
