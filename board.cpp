#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>vec(n);
    for(int i = 0 ; i< n ;i++){
    	cin>>vec[i];
	}
    sort(vec.begin() , vec.end(),greater<int>());
    
    int sumleft = 0 , sumright =  0;
    for(int i =  0 ; i< n ;i++){
    	if(sumleft < sumright){
    		sumleft += vec[i];
		}
		else{
			sumright += vec[i];
		}
	}
	int ans = min( abs(sumleft - sumright) , abs(sumright - sumleft));
    cout<<ans;
    return 0;
}

