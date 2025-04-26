#include<bits/stdc++.h>
using namespace std;

void Backtrack(vector<int>&vec , int start,vector<int>&result){
	if(result.size() != 0 ){
		
	
		for(int i = 0 ; i < result.size() ; i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
		
	
/*	
	vec[start] = 1;
	Backtrack(vec,start+1);
	vec[start] = 0;
	Backtrack(vec,start+1);
	
	
*/

	for(int i = start ; i < vec.size() ; i++){
		result.push_back(vec[i]);
		Backtrack(vec,i+1,result);
		result.pop_back();
	}	
}




int main(){
	int n = 3;
	vector<int>vec = {1,2,3};
	vector<int>result;
	Backtrack(vec,0,result);
	
	return 0;
}
