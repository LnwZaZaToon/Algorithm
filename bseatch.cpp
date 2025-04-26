#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>&vec,int low , int high,int mid){
	int n1 = mid-low+1;
	int n2 = high-mid;
	vector<int>A(n1);
	vector<int>B(n2);
	for(int i = 0 ; i< n1 ; i++){
		A[i] = vec[low+i];
	}
	for(int i = 0 ; i < n2 ; i++){
		B[i] = vec[mid+1+i];
	}
	int  i = 0 ,j = 0 , k = low;
	
	while(i < n1 && j < n2){
		if(A[i] <= B[j]){
			vec[k++] = A[i++];
		}
		else{
			vec[k++] = B[j++];
		}
	}
	while(i< n1){
		vec[k++] = A[i++];
	}
	while(j<n2){
		vec[k++] = B[j++];
	}
}




void MergeSort(vector<int>&vec,int low , int high){
	if(high > low){
		int mid = (low + high )/2;
		MergeSort(vec,low,mid);
		MergeSort(vec,mid+1,high);
		Merge(vec,low,high,mid);
	}
}

int BLeft(vector<int>&vec , int low , int high ,int target){
	if(high >= low ){
		int mid = (low+high)/2;
		
		if(vec[mid] == target){
			int index = BLeft(vec,low,mid-1,target);
			return (index ==0)?mid:index;
		}
		else if(vec[mid] < target){
			return BLeft(vec,mid+1,high,target);
		}
		else{
			return BLeft(vec,low,mid-1,target);
		}
		
	}
	return 0;
	
}
int BRight(vector<int>&vec , int low , int high ,int target){
	if(high >= low ){
		int mid = (low+high)/2;
		
		if(vec[mid] == target){
			int index = BRight(vec,mid+1,high,target);
			return (index ==0)?mid:index;
		}
		else if(vec[mid] < target){
			return BRight(vec,mid+1,high,target);
		}
		else{
			return BRight(vec,low,mid-1,target);
		}
		
	}
	return 0;
	
}



int main(){
	vector<int>vec = {5,6,8,9,9,9,3,3,3,2,1,8,4,2,6};
	int target = 1;
	MergeSort(vec,0,vec.size()-1);
	for(int i = 0 ; i < vec.size() ; i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	int a = BLeft(vec,0,vec.size(),target);
	int b = BRight(vec,0,vec.size(),target);
	cout<< b-a+1;
	
	
	
	return 0;
}
