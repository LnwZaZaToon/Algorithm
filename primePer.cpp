#include<bits/stdc++.h>
using namespace std;

void Permutation(vector<int>&vec , int start){
	
	if(start == vec.size()){
		for(int i = 1 ; i < vec.size() ; i++){
			cout<<vec[i]<<" ";
		}
		cout<<endl;
	}
	
	
	for(int i = start ; i < vec.size() ;i++){
		swap(vec[i] , vec[start]);
		Permutation(vec,start+1);
		swap(vec[i],vec[start]);
	}
	
}




using namespace std;
int main(){
	int n ;
	cin>> n;
	vector<int>vec(n+1);
	for(int i = 1 ; i <=n ; i++){
		vec[i] = i;
	}	
	Permutation(vec,1);
	return 0;
}
