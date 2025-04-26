#include<iostream>
#include<vector>
using namespace std;


int Divide(vector<int>&vec , int low , int high ,int target){
	if(high > low ){
		int mid = (low+high)/2;
		int left = Divide(vec,low,mid,target);
		int right = Divide(vec,mid+1,high,target);
		return left + right;
	}
	else if( high == low ){
		return (vec[low] == target)? 1 : 0;
	}
	return 0;
	
}




int main(){
	int n , target;
	cin>>n>>target;
	
	vector<int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	int ans = Divide(vec,0,n-1,target);
	(ans>0)?cout<<ans<<endl:cout<<"-1"<<endl;
	
	return 0;
}
