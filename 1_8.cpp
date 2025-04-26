#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void Calculate(int arr[] , int n){
	int sum = 0;
	int maxCount = INT_MIN;
	for(int i = 0 ; i< n-1 ; i++){
		for(int j = i+1 ; j< n ;j++){
			sum = 0;
			for(int z =i ; z<= j ;z++){
				sum += arr[z];
				maxCount = max(maxCount,sum);
			}
		}
	}
	cout<<maxCount;
}


int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i = 0 ; i< n ;i++){
		cin>>A[i];
	}
	int size = sizeof(A)/sizeof(A[0]);
	Calculate(A,size);
	

	return 0;
}
