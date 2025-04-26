#include<iostream>
#include<cmath>
using namespace std;


int Sum(int n){
	if(n==1){
		return 1;
	}
	return pow(n,3) + Sum(n-1);
}



int main(){
	cout<<Sum(3);
	
	return 0;
}
