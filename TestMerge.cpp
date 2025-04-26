#include<iostream>
#include<vector>
using namespace std;


int Merge(vector<int>&vec , int low ,int mid,int high ){
	int left = mid-low+1;
	int right = high - mid;
	vector<int> A(left),B(right);
	for(int i =0 ; i< left ;i++){
		A[i] = vec[low+i];
	}
	for(int i =0 ; i< right ;i++){
		B[i] = vec[mid+1+i];
	}
	int i = 0 , j = 0;
	int res = 0;
	int k = low;
	while(i<left && j <right){
		if(A[i] <= B[j]){
			vec[k] = A[i];
			i++;
		}
		else{
			vec[k] = B[j];
			j++;
			res +=(left-i);
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
	return res;
	
}

int MergeSort(vector<int>&vec , int low ,int high ){
    int res = 0;
    if (low < high) { 
        int mid = (low + high) / 2;
        res += MergeSort(vec, low, mid);       
        res += MergeSort(vec, mid + 1, high);   
        res += Merge(vec, low, mid, high);     
    }
    return res;  
}


int main(){
	int n ;
	cin >> n;
	vector<int>vec (n);
	for(int i = 0 ; i < n ;i++){
		cin>>vec[i];
	}
	cout<<MergeSort(vec,0,n-1);
/*	for(int i = 0 ; i < n ;i++){
		cout<<vec[i]<<" ";
	}
	*/
	return 0;
}
