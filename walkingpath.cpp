#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
   	int n , m , k;
   	cin>>n>>m>>k;
   	vector<int>vec(m),gap;
   	for(int i = 0 ; i< m ;i++){
   		cin>>vec[i];
	}
	for(int i = 1 ; i< m ;i++){
		int x = vec[i]-vec[i-1]-1;
		gap.push_back(x);
	}
	int ans = 0;
	sort(gap.begin(),gap.end(),greater<int>());
   	for(int i = 0 ; i< gap.size() ;i++){
   		ans += gap[i];
	}
	
	for(int i = 0 ; i<gap.size() && i<k-1 ; i++){ // 1 time
		ans -= gap[i];
	}	
	cout<<ans;
}
