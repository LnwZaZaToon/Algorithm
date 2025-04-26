#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CrossSum(vector<int>&vec , int low , int high,int mid){
	
	int sumLeft = 0;
	int MaxLeft=  -10000;
	for(int i = mid ;  i >=  low ; i--){
		sumLeft += vec[i];
		MaxLeft = max(sumLeft , MaxLeft);
	}
	int sumRight = 0;
	int MaxRight = -10000;
	for(int i = mid+1 ; i<= high ; i++ ){
		sumRight += vec[i];
		MaxRight = max(sumRight,MaxRight);
	}
	
	int result = MaxRight + MaxLeft;
	return result;	
	
}

int Divide(vector<int>&vec ,int low , int high ) {
	if(low == high ){
		return vec[low];
	}
	int mid = (low+high)/2;
	int left = Divide(vec,low,mid);
	int right = Divide(vec,mid+1,high);
	int Cross = CrossSum(vec,low,high,mid);
	return max(max(left,right),Cross);
}

int main() {
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0 ; i< n; i++){
    	cin>>vec[i];
	}
	int ans = Divide(vec,0,n-1);
	cout<<ans;

    return 0;
}

