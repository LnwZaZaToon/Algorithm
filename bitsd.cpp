#include <bits/stdc++.h>

using namespace std;

int ar[10000];



int main() {
    int n;
    cin >> n;
    vector<int>vec;
    int count =  0;
  	while(n!= 0){
  		int a = n%2;
  		if(a == 1) count++;
  		vec.push_back(a);
  		n /=2;
	  }
	  reverse(vec.begin(), vec.end() );
	  for(int i = 0 ; i< vec.size() ; i++){
	  	cout<<vec[i];
	  }
	  cout<<endl;
	  cout<<count;
    return 0;
}

