#include<bits/stdc++.h>
using namespace std;


int main(){
	string str1 = "abcde";
	string str2 = "cde";
	
	vector<vector<int>>vec(str2.size()+1 , vector<int>(str1.size()+1 , 0));
	
	for(int i = 1 ; i < vec.size() ; i++){
		for(int j = 1 ; j < vec[i].size()  ;j++){
			if(str2[i-1] == str1[j-1]){
				vec[i][j] = vec[i-1][j-1]+1;
			}
			else{
				vec[i][j] = max( vec[i-1][j] , vec[i][j-1] );
			}
		}
	}
	cout<< vec[str2.size()][str1.size()];
	
	
	return 0; 
}
