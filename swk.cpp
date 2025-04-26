#include<bits/stdc++.h>
using namespace std;



void Merge(vector<int>&vec,int low , int high,int mid){
	int n1 = mid-low+1;
	int n2 = high-mid;
	vector<int>A(n1);
	vector<int>B(n2);
	for(int i = 0 ; i< n1 ; i++){
		A[i] = vec[low+i];
	}
	for(int i = 0 ; i < n2 ; i++){
		B[i] = vec[mid+1+i];
	}
	int  i = 0 ,j = 0 , k = low;
	
	while(i < n1 && j < n2){
		if(A[i] <= B[j]){
			vec[k++] = A[i++];
		}
		else{
			vec[k++] = B[j++];
		}
	}
	while(i< n1){
		vec[k++] = A[i++];
	}
	while(j<n2){
		vec[k++] = B[j++];
	}
}




void MergeSort(vector<int>&vec,int low , int high){
	if(high > low){
		int mid = (low + high )/2;
		MergeSort(vec,low,mid);
		MergeSort(vec,mid+1,high);
		Merge(vec,low,high,mid);
	}
}





int main(){
	int n ;
	cin >> n;
	vector<int>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i];
	}
	MergeSort(vec,0,n-1);
//	reverse(vec.begin() , vec.end());
/*	for(int i = 0 ; i < n ; i++){
		cout<<vec[i]<<" ";
	}*/
	vector<int>newvec;
	for(int i = 0 ; i< n ; i++){
		vector<int>temp;
		while(vec[i] != 0){
			int a = vec[i]%10;
			temp.push_back(a);
			vec[i] = vec[i] / 10;
		}
		reverse(temp.begin() , temp.end());
		for(int i = 0 ; i< temp.size() ; i++){
			newvec.push_back(temp[i]);
		}
	}
	int maxZ = newvec[0];
	for(int i = 0 ; i < newvec.size() ; i++){
		cout<<newvec[i];
		maxZ = max(maxZ , newvec[i]);
	}
	vector<int>count(maxZ+1 , 0);
	
	for(int i = 0  ; i< newvec.size() ; i++){
		count[newvec[i]]++;
	}
	cout<<endl;
	int Maxcount = count[0];
	for(int i= 0 ; i< count.size() ; i++){
		Maxcount = max(Maxcount , count[i]);
	}
	for(int i = 0 ; i<count.size() ; i++){
		cout<<count[i]<<" ";
	}
	for(int i = 0 ; i<count.size() ; i++){
		if(count[i] == Maxcount){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	vector<int>newvec2;
	for(int i = 1 ; i< newvec.size() ; i++){
		if(i==1){
			newvec2.push_back(newvec[0]);
		}
		if(newvec[i] != newvec[i-1]){
			newvec2.push_back(newvec[i]);
		}
	}
	for(int i = 0 ; i< newvec2.size() ; i++){
		cout<<newvec2[i];
	}
	
	
	
	return 0;
}
