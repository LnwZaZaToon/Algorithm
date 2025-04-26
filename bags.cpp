#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

	vector<int>Real;
    sort(books.begin(), books.end());  
    for(int i = 0 ; i <n-2 ; i++){
    	int left = i + 1; 
        int right = n - 1;
    	int flag = false;
    	vector<int>result;
    	while(left <= right){
    		int sum = books[left] + books[right] + books[i];
    		if(sum == k ) {
    			flag = true;
    			result = {books[left] , books[right] , books[i]};
    			break;
			}
			else if(sum < k){
				left++;
			}
			else{
				right--;
			}
		}
		if(flag){		
			Real = result;
			break;
		}
	}
    for(int i = 0 ; i < Real.size() ; i++){
    	cout<< Real[i] <<" ";
	}
    return 0;
}

