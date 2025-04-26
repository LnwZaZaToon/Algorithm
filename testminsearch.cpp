#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Bsearch(vector<int>&vec , int low , int high ,int target){
	int i = 0;
	int j = 0;
	int minz = 100000;
	while(high > low ){
		int mid = vec[low] + vec[high];
		int data = abs(vec[low]-vec[high]);
		if( mid == target){
			if(minz>data){
				minz = data;
				i = low;
				j = high;
			}
			low++;
			high--;
		}
		else if(mid < target){
			low++;
		}
		else{
			high--;
		}
	}
	cout<< vec[i] <<" "<< vec[j];
	
}




int main(){
	int n ,target;
	cin >> n>>target;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	Bsearch(vec,0,vec.size()-1,target);
	
	return 0;
}
