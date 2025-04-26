#include<bits/stdc++.h>
using namespace std;


void Light(vector<int>&vec , int start , int end,int k ,int &Realcount){
	if(start == end ){
		int count = 0;
		for(int i =  0 ; i< vec.size() ; i++){
			if(vec[i] == 1 ){
				count++;
			}
		}
		if(count == k){
			Realcount++;
		}
		return;
	}
	vec[start] = 1;
	Light(vec,start+1,end,k,Realcount);
	vec[start] = 0;
	Light(vec,start+1, end,k,Realcount);
	
}





int main(){
	int n , k;
	cin>>n >> k;
	vector<int>vec(n);
	int Realcount = 0;
	Light(vec,0,n,k,Realcount);
	cout<<Realcount;
	
	
	return 0;
}
