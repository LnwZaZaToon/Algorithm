#include<iostream>
using namespace std;


int Divide(int left,int right,int n,int &count){
	if(right >=left){
		int mid = (left+right)/2;
		count++;
		
		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid < n){
			return Divide(mid+1,right,n,count);
		}
		else{
			
			return Divide(left,mid-1,n,count);
		}
	}
	return -1;
}


int main(){
	int n ;
	cin>>n;
	int count = 0;
	int ans = Divide(0,n,n,count);
	cout<<ans<<" "<<count;
	
	
	return 0;
}
