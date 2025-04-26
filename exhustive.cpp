#include<bits/stdc++.h>
using namespace std;



void Test(vector<int>&vec,int start ,int n){
	if(start == n){
		for(int i = 0 ; i< n;  i++){
			cout<<vec[i]<<" ";
		}
	
		cout<<endl;
		return;
	}
	
	
	vec[start] = 1;
	Test(vec,start+1,n);
	vec[start] = 0;
	Test(vec,start+1,n);
	
}






int main(){
	int n = 5;
	vector<int>vec(n);
	Test(vec,0,n);
	
	
	return 0;
}
