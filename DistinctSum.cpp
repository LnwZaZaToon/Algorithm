#include<iostream>
#include<vector>
using namespace std;


long int Check(vector<long int>& vec, int n) {
    // Step 1: Find the maximum value in the array
    long int sumMax = vec[0];
    for (int i = 0; i < n; i++) {
        sumMax = max(sumMax, vec[i]);
    }

    // Step 2: Create a frequency array
    vector<long int> arr(sumMax + 1, 0);
    for (int i = 0; i < n; i++) {
        arr[vec[i]] += 1;
    }

    // Step 3: Calculate the sum of unique elements
    long int sum = 0;
    for (long int i = 0; i <= sumMax; i++) { // Iterate through the frequency array
        if (arr[i] == 1) { // Only include elements that appear exactly once
            sum += i;
        }
    }

    return sum;
}




int main(){
	long int n ;
	cin>>n;
	vector<long int>vec(n);
	for(int i = 0 ; i<n ;i++){
		cin>>vec[i];
	}
	cout<<Check(vec,n);
}
