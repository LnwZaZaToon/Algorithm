#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>A(n);
	vector<int>B(n);
	vector<int>vec(100000,0);
	for(int i = 0  ; i< n ; i++){
		cin>>A[i];
	}
	for(int i = 0  ; i< n ; i++){
		cin>>B[i];
	}
	for(int i = 0 ; i< n ; i++){
		for(int j = A[i] ; j <= B[i] ; j++){
			vec[j]++;
		}
	}
	int maxz = 0;
	int start = 0 , end= 0;
	bool flag = true;
	for(int i = 0 ; i< vec.size() ; i++){
		if(vec[i] > maxz){
			maxz = vec[i];
			start = i;
			end = i;
		}
		else if(vec[i] == maxz && flag){
			end = i;
		}
		else if(vec[i] < maxz){
			flag = false;
		}
	}
	
	cout<< start <<" "<< end<<" "<< maxz <<endl;
/*	for(int i = 0 ; i< 20 ; i++){
		cout<<vec[i]<<" ";
	}*/
	
	return 0;
}
