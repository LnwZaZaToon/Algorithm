#include<bits/stdc++.h>
using namespace std;


int Power(int a , int n ,int &count){
	if(n == 0 ){
		return 1;
	}
	if(n == 1 ){
		return a;
	}
	int temp = Power(a,n/2,count);
	count++;
	if(n%2 == 0){
		return temp*temp;
	}
	else{
		count++;
		return temp*temp*a;
	}
}




int main(){
	int a , n;
	cin>>a>>n;
	int count = 0;
	int z = Power(a,n,count);
	cout<<z<<" "<<count;
	
	return 0;
}
