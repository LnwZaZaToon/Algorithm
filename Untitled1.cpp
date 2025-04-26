#include<bits/stdc++.h>
using namespace std;

int TopDown(int n , int m ){
	if(n == m ) return 1;
	if( n== 0 || m == 0 ) return 1;
	return TopDown(n-1 , m-1  ) + TopDown(n-1,m);
}



int main(){
	int n , m;
	cin>>n  >> m;
	cout<< TopDown(n,m);
	
	return 0;
}
