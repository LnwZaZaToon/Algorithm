#include<bits/stdc++.h>
using namespace std;


bool IsPrime(int n){
	if(n<2){
		return false;
	}
	for(int i = 2 ; i*i <= n ; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}



bool IsValid(vector<int>&vec){
	for(int i = 1 ; i<vec.size()-1 ; i++){
		if(!IsPrime(vec[i]+vec[i+1])) return false;
	}
	return IsPrime(vec[vec.size()-1]+ vec[1]) ;
}





void Test(vector<int>&vec,int start ,int n){
	if(start == n+1){
		//if(IsValid(vec)){
			for(int i = 1 ; i<= n;  i++){
				cout<<vec[i]<<" ";
			}
			cout<<endl;
	//	}
	
		return;
	}
	
	
	for(int i = start ; i<= n ; i++){
		swap(vec[i],vec[start]);
		Test(vec,start+1,n);
		swap(vec[i],vec[start]);
	}
	
}






int main(){
	int n;
	cin>>n;
	vector<int>vec(n+1);
	for(int i = 1 ; i<= n ; i++ ){
		vec[i] = i;
	}
	Test(vec,1,n);
	
	
	return 0;
}
