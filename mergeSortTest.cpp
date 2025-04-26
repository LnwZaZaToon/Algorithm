#include<iostream>
#include<vector>
using namespace std;


void MergeSort(vector<int>&vec , int low , int high ,int mid){
	int left = mid-low+1;
	int right = high-mid;
	vector<int>A(left);
	vector<int>B(right);
	
	for(int i =  0 ; i< left ; i++){
		A[i] = vec[low+i];
	}
	for(int i = 0 ; i < right ; i++){
		B[i] = vec[mid+1+i];
	}
	int i = 0 , j = 0 , k = low;
	
	while(i < left && j < right){
		if(A[i] <= B[j]){
			vec[k] =  A[i];
			i++;
		}
		else{
			vec[k] = B[j];
			j++;
		}
		k++;
	}
	while(i<left){
		vec[k] = A[i];
		i++;
		k++;
	}
	while(j<right){
		vec[k] = B[j];
		j++;
		k++;
	}
}


void MergeSort(vector<int>&vec , int low , int high,vector<int>&count){
	if(high> low){
		int mid = (low+high)/2;
		count.push_back(vec[mid]);
		MergeSort(vec,low,mid,count);
		MergeSort(vec,mid+1,high,count);
		MergeSort(vec,low,high,mid);
	}
}



int main(){
	int n;
	cin>>n;
	vector<int>vec(n);
	vector<int>count;
	vector<int>temp;
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	MergeSort(vec,0,n-1,count);
	MergeSort(count,0,count.size()-1,temp); 
	for(int i = 0 ; i< count.size() ;i++){
		cout<<count[i]<<" ";
	}
	int sum = 0;
	for(int i = 0 ; i<count.size() ; i++){
		sum+=count[i];
	}
	cout<<endl;
	cout<<sum;
	return 0;
}
