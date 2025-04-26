#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

void merge(vector<long int>&vec,long int low ,long int mid,long int high){
	long int n1 = mid-low+1;
	long int n2 = high - mid;
	vector<long int>a(n1);
	vector<long int>b(n2);
	for(long int i = 0 ; i< a.size() ;i++){
		a[i] = vec[low+i];
	}
	for(long int i = 0 ; i< b.size() ;i++){
		b[i] = vec[mid+1+i];
	}
	long int i=0, j=0 ,k=low ;
	while(i<n1 && j <n2){
		if(a[i] <= b[j]){
			vec[k] = a[i];
			i++;
		}
		else{
			vec[k] = b[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		vec[k] = a[i];
		i++;
		k++;
	}
	while(j<n2){
		vec[k] = b[j];
		j++;
		k++;
	}
}





void mergesort(vector<long int>&vec,long int low ,long int high){
	if(low < high){
		long int mid = (low+high)/2;
		mergesort(vec, low , mid);
		mergesort(vec,mid+1, high);
		merge(vec,low,mid,high);
	}
}

void Check(vector<long int>&vec,int target){
	int l=0;
	int r = vec.size()-1;
	int min = INT_MAX;   
	int i=0,j=0;
	while(l<r){
		int mid = vec[l]+vec[r];
		int minus = abs(vec[l]-vec[r]);
		if(mid == target) {			
			if(minus<min){
				min = minus;
				i = l;
				j = r;
			}
		l++;
		r--;
		}
		else if(mid > target){
			r--;
		}	
		else{
			l++;
		}
	}
	cout<< vec[i]<<" "<<vec[j];
	
}




int main(){
	long int n , target;
	cin>>n >> target;
	vector<long int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	long int size  = vec.size()-1;
	mergesort(vec,0,size);
/*	for(int i = 0 ; i< n ;i++){
		cout<<vec[i]<<" ";
	}*/
	Check(vec,target);
	
	
	
	
	return 0;
}

