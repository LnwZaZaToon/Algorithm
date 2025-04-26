#include<iostream>
using namespace std;

int main(){
	int arr[] = {5,3,2,7,9,10,8,4,1};
	int n = 9;
	int count = 0;
	for(int i = 1 ; i< n ;i++){
		int key = arr[i];
		int j = i-1;
		while(j >=  0 && arr[j] > key){
			count++;
			arr[j+1] = arr[j];
			j = j-1;
			
		}
		arr[j+1] = key;
		
	for(int i = 0 ; i < n ;i++){
		cout<< arr[i] << " ";
	}
	cout<<endl;
	}
	cout<< count;

	
	
	return 0;
}
