#include<bits/stdc++.h>
using namespace std;

int BottomUp(int n ,int k){
	vector<int> vec(n+1 , 0);
	vec[0] = 0;
	vec[1] = 1;
	for(int i = 2 ; i<vec.size() ; i++){
		vec[i] = i*vec[i-1];		
	}
	return vec[n]/ ( vec[n-k] * vec[k] ) ;
}

int main(){
	int n , k ; 
	cin>> n >> k;
	cout << BottomUp(n , k);
	
	
	
	
	return 0;
}
