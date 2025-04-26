#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin>>n;
	vector<int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	
	double sum = 0; //5+15+ 28
	double prefixSum = 0; //5 + 10 +13
    for (int i = 0; i < n; i++) {
        prefixSum += vec[i];      
        sum += prefixSum;         
    }
	double ans = sum/vec.size();	
	cout<<fixed<<setprecision(2)<<ans;
	
	return 0;
	// 5  10  13
}
