#include<iostream>
#include<vector>
using namespace std;

int B1Search(vector<int>&vec , int low , int high , int target){
	if(low>high){
		return -1;
	}
	int mid = (low + high) / 2;
	if(vec[mid] == target){
		int index = B1Search(vec,low,mid-1,target);
		return (index == -1 )? mid : index;
	}
	else if(vec[mid] < target){
		return B1Search(vec,mid+1,high,target);
	}
	else{
		return B1Search(vec,low,mid-1,target);
	}
	return -1;
}




int main(){
	vector<int>vec = {1,2,2,2,3,4,5};
	int target = 2;
	cout<<B1Search(vec,0,vec.size()-1 , target);
	
	return 0;
}
