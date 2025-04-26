#include<iostream>
#include<vector>
using namespace std;


int main(){
	int n ;
	cin >> n ;
	vector<int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	int Rmax = vec[0];
	for(int i = 0 ; i< n ;i++){
		Rmax = max(vec[i],Rmax);
	}
	vector<int>vec2(Rmax+1,0);
	for(int i = 0 ; i<n ;i++ ){
		vec2[vec[i]]++;
	}
	int count = 0;
	for(int i = 0 ; i<vec2.size() ; i++){
		if(vec2[i] != 0){
			count++;
		}
	} 
	cout<< count;
	
	
	return 0;
}
