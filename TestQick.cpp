#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int partition(vector<int>&vec , int low , int high ){
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



int QuickSelect(vector<int>&vec,int low, int high , int k){
	if(high >= low){
		int p = partition(vec,low,high);
		if(p == k-1){
			return vec[p];
		}
		else if(p < k-1){
			QuickSelect(vec,p+1,high,k);
		}
		else{
			QuickSelect(vec,low,p-1,k);
		}
		
	}
}



int main(){
	int n , k;
	cin>>n>>k;
	vector<int>vec(n);
	for(int i = 0 ; i < vec.size() ; i++){
		cin>>vec[i];
	}
	int ans = QuickSelect(vec,0,vec.size()-1,k);
	int sum = 0;
	for(int i = 0 ; i< k  ;i ++){
		sum+=vec[i];
	}
	cout<<sum;
	return 0;
}
