#include<bits/stdc++.h>
using namespace std;

double findMean(vector<int>&vec, int n,double total){
	if(n == 0) return vec[n]/total;
	
	return vec[n]/total + findMean(vec,n-1,total);
	
}


int main(){
	double n ;
	cin>>n ;
	vector<int>vec(n);
	for(int i=  0 ; i < n; i++){
		cin>>vec[i];
	}
	cout<<fixed<< setprecision(2)<< findMean(vec,n-1,n);
	
	
	return 0;
}
