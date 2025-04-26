#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>vec = { 1,5,2,10} ;
	int n = 4 , w = 13;
	int count = 0;
	sort(vec.begin() , vec.end() , greater<int>());
	for(int i=  0 ; i <  n; i++){
		while(w >= vec[i]){
			w -= vec[i];
			count++;
		}
	}
	cout << count ;
	
	return 0;
}
