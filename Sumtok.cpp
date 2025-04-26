#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>prices(n);

pair<int,int> TopDown(vector<int>&vec , int j,int n  , vector<vector<pair<int,int>>>&memo){
	if( n == 0) return {0,0};
	if(j >= vec.size() ) return {INT_MIN , INT_MIN};
	if( n < 0) return {INT_MIN , INT_MIN};

	if (memo[j][n].first != -1) return memo[j][n];

	
	int MAX = INT_MIN;
	int MIN = INT_MAX;
	
	for(int i = j  ; i < vec.size() ; i++){
		if(n - vec[i] >= 0){
			auto res = TopDown(vec,i+1 , n-vec[i],memo);		
			if(res.first != INT_MIN){
				MAX = max(MAX,res.first+1);
				MIN = min(MIN,res.second+1);
			}
		}
	}
	
	return memo[j][n] = {MAX,MIN};
}
/*
int TopDown2(vector<int>&vec , int j,int n ){
	if( n == 0) return 0;
	if(j >= vec.size() ) return INT_MAX;
	if( n < 0) return INT_MAX;
	
	int MIN = INT_MAX;

	
	for(int i = j  ; i < vec.size() ; i++){
		if(n - vec[i] >= 0){
			int res = TopDown2(vec,i+1 , n-vec[i]);
			if(res != INT_MAX){
				MIN = min(MIN,res+1);
			}
		}
	}
	return MIN;
}

*/

int main(){
	cin >> n >> k;
	vector<int>vec(n);
	vector<vector<pair<int,int>>> memo(n+1 , vector<pair<int,int>>(k+1 , {-1,-1}));

	for(int i= 0 ; i < n ; i++){
		cin>>vec[i];
	}
	auto ans = TopDown(vec,0,k,memo) ;
	if(ans.first != INT_MIN || ans.second != INT_MAX){
		cout<< "Yes"<< " "<< ans.first << " " << ans.second;
	}
	else{
		cout<<"No";
	}
	
	// cout << TopDown2(vec,0,k);
	
	
	
	return 0;
}
