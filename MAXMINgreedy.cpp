#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>vec(n);
	for(int i = 0 ; i< n ; i++){
		cin>>vec[i];
	}
	sort(vec.begin() , vec.end() , greater<int>());
	
	int sum1 = 0, sum2 = 0;
	for(int i = 0 ; i< n ; i++){
		if(sum1 >= sum2){
			sum2 += vec[i];
		}
		else{
			sum1 +=vec[i];
		}
	}
	cout<< abs(sum2-sum1);
	
	
	
	return 0;
}
