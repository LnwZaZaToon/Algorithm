#include<iostream>
#include<vector>
using namespace std;


bool Check(vector<long int>&vec , int n){
	if(n == 0){
		return true;
	}
	else if( vec[n] < vec[n-1] ){
		return false;
	}
	return Check(vec,n-1);
	
	
}



int main(){
	long int n ;
	cin>>n;
	vector<long int>vec(n);
	for(int i = 0 ; i<n ;i++){
		cin>>vec[i];
	}
	if(Check(vec,n-1)){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
