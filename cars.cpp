#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a , int b){
	return a > b;
}

int main(){
	long n , target;
	cin>>n >> target;
	vector<long>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	sort(vec.begin() , vec.end() , compare);
	cout<<vec[target-1];
	
	return 0;
}
