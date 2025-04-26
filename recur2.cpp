#include<iostream>
#include<cmath>
using namespace std;


int Sum(int arr[] ,int n){
	if(n==1){
		return arr[0];
	}
	return arr[n-1] + Sum(arr,n-1);
}



int main(){
	
	cout<<Sum(3);
	
	return 0;
}
