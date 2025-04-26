#include<bits/stdc++.h>
using namespace std;

int TopDown(vector<int>&vec , int k , vector<int>&memo ){
	if( k == 0) return 0;
	if(k < 0 ) return INT_MAX;
	if(memo[k] != -1) return memo[k];
	
	int count = INT_MAX;
	for(int i = 0 ; i < vec.size() ; i++){
		if(k >= vec[i]){
			int res = TopDown(vec,k-vec[i],memo);
			if(res != INT_MAX){
				count = min(count , res+1);
			}
		}
	}
	return memo[k] = count;
}




int main(){
	int n , k  ;
	cin >> n >> k;
	vector<int>vec(k);
	vector<int>memo(n+1,-1);
	for(int i = 0 ; i < k ; i++){
		cin >> vec[i];
	}
	cout << TopDown(vec , n,memo);
	
	return 0;
}
