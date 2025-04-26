#include<iostream>
#include<vector>
using namespace std;

int Check(vector<char>&vec,int w){
	int count = 0;
	vector<bool>check(vec.size(),false);
	for(int i = 0 ; i<vec.size() ; i++){
		if(vec[i]=='P'){
			int start = max(0, i - w);  // The left boundary
			int end = min(int(vec.size() - 1), i + w);  // The right boundary
			for(int j =start ; j <= end ; j++){
				if(vec[j] == 'T' && !check[j]){
					count++;
					check[j] = true;
					break;
				}
			}
		}
	}
	return count;
}


int main(){
	
	int n , w;
	cin>>n>>w;
	vector<vector<char>>vec(n,vector<char>(n));
	for(int i = 0 ; i< n ; i++){
		for(int j = 0 ; j <n  ;j ++){
			cin>>vec[i][j];
		}
	}
	int count = 0;
	for(int i = 0 ; i<n  ;i++){
		count+=Check(vec[i],w);
	}
	cout<<count;
	
	
	return 0;
}
