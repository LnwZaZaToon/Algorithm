#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count = 0;
	while(n > 0){
		int x = n%2;
		if(x == 1) count++;
		n/=2;
	}
	cout<<count;
	
	
	
}
