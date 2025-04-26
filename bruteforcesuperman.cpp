#include<iostream>
using namespace std;

int main(){
	long long x;
	cin>>x;
	
	long long ans = 0;
	for(int i = 1 ; i<= 100000000; i++){
		long long data = i*(i+1)/2;
		cout<<i<<endl;
		if(data == x){
			ans = i;
			break;
		}
	}
	
	
	if(ans != 0){
		cout<<ans;
	}
	else{
		cout<<"0";
	}
	
	
	return 0;
}
