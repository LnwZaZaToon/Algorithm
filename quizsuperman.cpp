#include<iostream>
using namespace std;
#define MAX 20000000000


long long Divide(long long low , long long high , long long x){
	long long left = low;
	long long right = MAX;
	

	
	while(right>=left){
		long long mid = (right+left)/2;
		long long data = mid*(mid+1)/2;
	//	cout <<mid <<endl;
		if( data == x){
			return mid;
		}
		else if( data < x){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return 0;
}



int main(){
	long long x;
	cin>>x;
	int ans = Divide(0,x,x);
	
	if(ans != 0){
		cout<<ans;
	}
	else{
		cout<<"0";
	}
	
	
	return 0;
}
