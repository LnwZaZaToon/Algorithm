#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&vec , int low , int high ){
	int pivot = vec[high];
	int i = low-1;
	for(int j = low ; j < high  ;j++){
		if(pivot>vec[j]){
			i++;
			swap(vec[i],vec[j]);
		}
	}
	swap(vec[i+1] , vec[high]);
	return i+1;
}

void QuickSort(vector<int>&vec , int low , int high){
	if( high > low ){
		int pa = partition(vec,low , high);
		QuickSort(vec,low,pa-1);
		QuickSort(vec,pa+1,high);
	}
}


int main(){
	vector<int>vec = { 9 ,8 ,7 , 6 ,5 };
	QuickSort(vec,0,vec.size()-1);
	for(int i= 0 ; i < vec.size() ; i++){
		cout<< vec[i]<< " ";
	}
	return 0;
}
