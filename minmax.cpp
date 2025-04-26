#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    vector<long long int>vec(n);
    for(int i = 0 ; i< n ;i++){
    	cin>>vec[i];
	}
	sort(vec.begin() , vec.end());
	cout<<vec[vec.size()-1]<<endl;
	cout<<vec[0];
}
