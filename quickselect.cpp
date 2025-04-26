#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>&vec , int low ,int high){
	int pivot = vec[high];
	int i = low-1;
	for(int j = low ; j < high ; j++){
		if(vec[j] <= pivot){
			i++;
			swap(vec[j],vec[i]);
		}
	}
	swap(vec[high],vec[i+1]);
	for(int i = low ; i<= high ;i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	return i+1;
}



int QuickSelect(vector<int>& vec, int low, int high, int target,int* count) {
    if (target <= 0 || target > high - low + 1) {
        return -1; 
    } 
    int p = partition(vec, low, high);
    if (p - low == target - 1) {
        return vec[p];
    }
    else if (p - low > target - 1) {
    	(*count)++;
        return QuickSelect(vec, low, p - 1, target,count);
      
    }
    else {
    	(*count)++;
        return QuickSelect(vec, p + 1, high, target-(p-low + 1),count);
        
    }
}




int main(){
	int n , k;
	cin>>n>>k;
	vector<int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	int count = 0;
	cout<<QuickSelect(vec,0,vec.size()-1,n-k+1,&count)<<" ";
	cout<<count<<endl;
/*	for(int i = 0 ; i < vec.size() ;i++){
		cout<<vec[i] << " ";
	}*/
	
	
	return 0;
}
