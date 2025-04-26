#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>&vec , int low,  int high){
	int pivot = vec[high];
	int i = low-1;
	for(int j = low ; j< high ; j++){
		if(vec[j] > pivot){
			i++;
			swap(vec[i],vec[j]);
		}
	}
	swap(vec[i+1],vec[high]);
	return i+1;
}


int QuickSelect(vector<int>&vec , int low,  int high,int target){
	if(high >= low){
		int p = partition(vec,low,high);
		if(p == target - 1 ){
			return vec[p];
		}
		else if( p < target-1 ){
			return QuickSelect(vec,p+1,high,target);
		}
		else{
			return QuickSelect(vec,low,p-1,target);
		}	
	}
	return -1;
	
	
	
}





int main(){
	int n ,target;
	cin>>n>>target;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}	
	int ans = QuickSelect(vec,0,vec.size()-1,target);
	int sum = 0;
	for(int i = 0 ; i< target  ;i ++){
		sum+=vec[i];
	}
	cout<<sum;
	
	return 0;
}
