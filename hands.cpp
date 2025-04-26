#include <bits/stdc++.h>
using namespace std;
int arr[3000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,k;cin >> n >> k;
	for(int i=0;i<n;i++) cin>> arr[i];
	sort(arr,arr+n,cmp);
	int ans=0;
	for(int i=0;i<n;i+=k){
		ans+=arr[i];
	}
	cout << ans;
	return 0;
}
