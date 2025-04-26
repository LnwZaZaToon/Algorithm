#include<iostream>
using namespace std;

int Divide(int arr[] , int low , int high){
	if(low == high){
		return arr[low];
	}
	int mid = (low+high)/2;
	int left = Divide(arr,low,mid);
	int right = Divide(arr,mid+1,high);
	return max(left,right);
}
int Divide2(int arr[] , int low , int high, int target){
	if(low == high ){
		if(arr[low] == target){
			return 0;
		}
		return arr[low];
	}
	

	int mid = (low+high)/2;
	int left = Divide2(arr,low,mid,target);
	int right = Divide2(arr,mid+1,high,target);
	return max(left,right);
}
int main(){
	int row , col ;
	cin>>row >> col;
	int n = row+col;
	int arr[n];
	
	for(int i =  0 ; i< n ;i++){
		cin>>arr[i];
	}
	
/*	for(int i =  0 ; i< n ;i++){
		cout<<arr[i] <<" ";
	}*/
	
	int max1 = Divide(arr,0,n-1);
	cout<< Divide2(arr,0,n-1,max1);
	
	
	return 0;
}
