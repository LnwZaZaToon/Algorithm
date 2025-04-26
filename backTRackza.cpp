#include<bits/stdc++.h>
using namespace std;

vector<int>result;/*
void Backtrack(vector<int>&vec , int start , int &count ){
		if(count > k) return; 
		if(count == k ){
			for(int i = 0 ; i < result.size() ; i++){
			cout << result[i] <<" ";
			}
			cout<<endl;	
		}
		

		for(int i = start ; i < vec.size() ; i++){
			result.push_back(vec[i]);
			count += vec[i];
			Backtrack(vec,i+1,count);
			count -= vec[i];
			result.pop_back();
		}
	
}*/
int k = 36;
vector<int>sum = {25,10,9,2};
void BackTrackZa(vector<int>&vec , int start ,int count){
	if(count == k){
		for(int i = 0 ; i < vec.size() ; i++){
			cout << vec[i] <<" ";
			}
		cout<<endl;			
		return;
	}
	if(count > k ) return;
	if(start == vec.size()) return;
	
	vec[start] = 1;
	count+= sum[start];
	BackTrackZa(vec,start+1,count);
	vec[start] = 0;
	count-= sum[start];
	BackTrackZa(vec,start+1 , count);
}



int main(){
	int n = 4;
	vector<int>vec(n);
	BackTrackZa(vec,0,0);
	return 0;
}
