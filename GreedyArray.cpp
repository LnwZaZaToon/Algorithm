#include<bits/stdc++.h>
using namespace std;


int main(){
	int m;
	cin>>m;
	for(int i = 0 ; i< m ; i++){
		int n;
		cin>>n;
		vector<int>vec1(n);
		vector<int>vec2(n);
		for(int j = 0 ; j< n ; j++){
			cin>>vec1[j];
		}
		for(int j = 0 ; j< n ; j++){
			cin>>vec2[j];
		}
		int k;
		cin>>k;
		
		sort(vec1.begin() , vec1.end() );
		sort(vec2.begin() , vec2.end(),greater<int>() );
		
		bool flag = false;
		for(int j = 0 ; j < n ; j++){
			if(vec1[j] + vec2[j] < k){
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	
	
	return 0;
}
