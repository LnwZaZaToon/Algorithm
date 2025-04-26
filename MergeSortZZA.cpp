#include<iostream>
#include<vector>
using namespace std;
int Merge(vector<int>&vec , int low , int high,int mid){
	int n1= mid-low+1;
	int n2= high-mid;
	vector<int>left(n1);
	vector<int>right(n2);
	int count = 0;
	for(int i = 0 ;i < n1  ; i++){
		left[i] = vec[low+i];
	}
	for(int i = 0; i < n2  ; i++){
		right[i] = vec[mid+1+i];
	}
	int i = 0, j = 0 , k = low;
	
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			vec[k++] = left[i++];
		}
		else{
			count += mid-i+1;
			vec[k++]  =right[j++];
		}
	}
	while(i < n1){
		vec[k++] = left[i++];
	}
	while(j < n2){
		vec[k++] = right[j++];
	}
	return count;
	
}



int MergeSort(vector<int>&vec , int low ,int high){
	int count = 0;
	if(high > low ){
		int mid = (low+high)/2;
		count += MergeSort(vec,low,mid);
		count += MergeSort(vec,mid+1,high);
		count += Merge(vec,low,high,mid);
	}
	return count;
}


int main(){
	vector<int>vec = {5,3,2,1,4};
	int count = MergeSort(vec,0,vec.size()-1);
	for(int i = 0 ; i< vec.size() ; i++){
		cout<<vec[i]<<" ";
	}
	cout<<count;
	return 0;
}
