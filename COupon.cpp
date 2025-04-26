#include <bits/stdc++.h>
using namespace std;

vector<int>result(3,0);
int maxz = 0;

void Combination(vector<int>& price, int start, int end, int k, vector<int>& vec,int sum) {
    if (vec.size() == 3 && sum <= k) {
    	if(maxz == k) return;
    	if(sum >= maxz){
    		maxz= sum;
    		for(int i = 0 ; i <vec.size() ; i++){
    			result[i] = vec[i];
			}
		}
        return;
    }
    
    for (int i = start; i < end; i++) {
        vec.push_back(price[i]);
        Combination(price, i+1, end, k, vec,sum+price[i]); 
        vec.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> price(n);
    vector<int> vec;
    
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
/*    for(int i = 0 ; i< n ; i++){
    	cout<<price[i] <<endl;
	}*/
    Combination(price,0,n,k,vec,0);
    sort(result.begin() , result.end());
    for(int i = 0 ; i< 3 ; i++){
    	cout<<result[i]<<" ";
	}
    
    return 0;
}

