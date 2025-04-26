#include<bits/stdc++.h>
using namespace std;

long long G( long long n ){
	vector<long long>vec(n+1,0);
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 1;
	for(int i = 3 ; i <= n ; i++){
		vec[i] = vec[i-1]+vec[i-2]-vec[i-3];
	}
	return vec[n];
	
}



int main(){
	long long n ;
	cin>> n;
	cout << G(n)<<endl;
	
	return 0;
}
