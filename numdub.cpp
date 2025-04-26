#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n ;
	cin>>n;
	vector<int>vec(n);
	for(int i= 0 ; i< n; i++){
		cin>>vec[i];
	}
	int Maxz=vec[0];
	for(int i = 0 ; i < n ; i++){
		Maxz = max(Maxz , vec[i]);
	}
	vector<int>vec2(Maxz+1,0);
	for(int i = 0 ; i < vec.size() ; i++){
		vec2[vec[i]]++;
	}
	for(int i = 0 ; i< vec2.size() ; i++){
		if(vec2[i] == 1){
			cout<<i;
		}
	}
	
	
	return 0;
}
