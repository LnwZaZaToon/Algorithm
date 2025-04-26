#include<bits/stdc++.h>
using namespace std;
/*

int TopDown(vector<int>&vec,int j , int n){
	if( n == 0  ) return 1;
	if(j >= vec.size()) return INT_MIN;
	if( n < 0 ) return INT_MIN;
	
	int count = 0;
	for(int i = j ; i < vec.size() ; i++){
		if( n - vec[i] >= 0){
			int  res = TopDown(vec,i+1 , n-vec[i]);
			if(res != INT_MIN){
				count++;
			}
		}
	}
	return count ;
}


*/

void BackTrack(vector<int>&vec , int start , int k,vector<int>&result ){
	
	if(  k == 0 ) {
	//	cout<< start <<" ";
		for(int i = 0 ; i < result.size() ; i++){
			cout<< result[i]<< " ";
		}
		cout<<endl;
		
		
		return ;
	}
	
	for(int i = start ; i < vec.size() ; i++){
		if(vec[i] <= k){
			result.push_back(vec[i]);
			BackTrack(vec,start+1,k-vec[i],result);
			result.pop_back();
		}
	}
	
	
	
	
}

/*void Permutation(vector<char>&vec , int start  ){
	
	if( start == vec.size() ) {
		//cout<< start <<" ";
		for(int i = 0 ; i < vec.size() ; i++){
			cout<< vec[i]<< " ";
		}
		cout<<endl;
		
		
		return ;
	}
	
	for(int i = start ; i < vec.size() ; i++){
		swap(vec[i],vec[start]);
		sort(vec.begin()+i , vec.end());
		Permutation(vec,start+1);
		swap(vec[i],vec[start]);
		}
	}
	
	*/
	
	

int main(){
	int n ,k ;
	cin>> n >>k;
	vector<int>vec(n);
	for(int i = 0 ; i <n ; i++){
		cin>> vec[i];
	}
	//cout<< TopDown(vec,0,k);
/*	sort(vec.begin() , vec.end());*/
	vector<int>result;
	
	BackTrack(vec,0,k,result);
	
	
/*5 12
25 10 9 2 1*/
	
	return 0;
}
