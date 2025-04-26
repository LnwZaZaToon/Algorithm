#include<bits/stdc++.h>
using namespace std;


class Gift{
public:
	int first;
	int second;
};




void Permutation(vector<Gift>&vec,vector<int>&x , int start , int end ,int &RealMin ){
	
	if(start == end){
		int sum1 = 0 , sum2 = 0;
		for(int i = 0 ; i< end ; i++){
			if(x[i] == 1 ){
				sum1 += vec[i].first;
				sum2 += vec[i].second;
			} 
			else{
				sum1 += vec[i].second;
				sum2 += vec[i].first;
			}
		}
		int ans = abs(sum1-sum2);
		RealMin = min(RealMin , ans);
		return;
	}
	
	x[start] = 1;
	Permutation(vec,x,start+1,end,RealMin);
	x[start] = 0;
	Permutation(vec,x,start+1,end,RealMin);
	
}


int main(){
	int n;
	cin>>n;
	vector<Gift>vec(n);
	vector<int>x(n);
	int RealMin = INT_MAX;
	for(int i = 0  ; i< n; i++){
		cin>> vec[i].first >> vec[i].second;
	}
	Permutation(vec,x,0,n,RealMin);
	cout<<RealMin;
	
	
	
	
	return 0;
}
