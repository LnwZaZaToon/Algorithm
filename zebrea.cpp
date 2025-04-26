#include<bits/stdc++.h>
using namespace std;

int TopDown(int n ,vector<int>&vec , vector<int>&memo){
	if(n == 0) return 1;
	if(n < 0) return 0;
	if(memo[n] != -1) return memo[n];
	
	int count = 0;
	for(int i = 1 ; i < vec.size() ; i++){
		count += TopDown(n-vec[i] , vec,memo);
	}
	return memo[n] = count;
	
}



int main(){
	int n , m;
	cin >> n >> m;
	vector<int>vec(m+1);
	for(int i = 1 ; i <= m ; i++){
		vec[i] = i;
	}
	vector<int>memo(n+1 , -1);
	cout<< TopDown(n , vec,memo);

	return 0;
}
