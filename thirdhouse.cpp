#include<iostream>
#include<algorithm>
using namespace std;



void Check(int arr[],int size,long int target){
	int count = 0;
	int total = 0;
	for(int i = 0 ; i< size ;i++){
		if(arr[i]+total <= target) {
			count++;
			total += arr[i];
		}
		else{
			break;
		}
		
	}
	cout<<"ans:  "<<count<<endl;
}



int main(){
	int T;
	cin>>T;
	for(int i = 0 ; i< T ;i++){
		int N;
		cin>>N;
		long int B;
		cin>>B;
		int arr[N];
		for(int i = 0 ; i<N ;i++){
			cin>>arr[i];
		}
		sort(arr,arr+N);
		Check(arr,N,B);		
	}	
	
	

		
	
	return 0;
}
