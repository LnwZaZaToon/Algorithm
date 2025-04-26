#include <iostream>
#include <algorithm>

using namespace std;

bool camp(int a,int b){
	return a>b;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,camp);
	if(n<3){
		cout<<n<<endl;
	}else{
		int max=0;
		int min=arr[0];
		for(int s=0;s<n;s++){
			int sum=1;
		for(int i=s+1;i<n;i++){
			if(arr[i]+min>arr[s]){
				min=arr[i];
				sum++;
			}
		}
		if(sum>max){
			max=sum;
		}
		}
		cout<<max<<endl;
	}
}
