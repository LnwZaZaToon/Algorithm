#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>&vec , int low ,int high){
	int pivot = vec[high];
	int i = low -1;
	for(int j = low ; j< high ; j++){
		if(vec[j] > pivot){
			i++;
			swap(vec[j],vec[i]);
		}
	}
	swap(vec[i+1],vec[high]);
	return i+1;
	
}

int QuickSelect(vector<int>&vec , int low ,int high , int k){
	if(high<low){
		return -1;
	}
	int p = partition(vec,low , high);
	if(p == k-1){
		return vec[p];
	}
	else if( p < k-1){
		return QuickSelect(vec,p+1,high,k);
	}
	else{
		return QuickSelect(vec,low,p-1,k);
	}
	

}

int FindK(vector<int>&vec , int low , int high){
	if(low == high ){
		return vec[low];
	}
	int mid = (low+high)/2;
	int left = FindK(vec,low,mid);
	int right = FindK(vec,mid+1,high);
	
	if(left == right){
		return left;
	}
	else{
		cout<<left <<" "<<right;
		return left;
	}
}

int main(){
	vector<int>vec = {3,3,3,3,3,3,3,2,3,3,3,3,3};
	cout<<FindK(vec,0,vec.size());
	/*int k = 3;
	int a = QuickSelect(vec,0,vec.size()-1,k);
	int sum = 0;
	for(int i = 0 ; i < k ; i++){
		sum+=vec[i];
	}*/
/*	for(int i = 0 ; i< vec.size() ; i++){
		cout<<vec[i]<<" ";
	}*/
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to check for differences using divide and conquer
int FindDifference(vector<int>& vec, int low, int high) {
    // Base case: If the subarray contains one element
    if (low == high) {
        return vec[low];
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;

    // Recursively find the values in each half
    int left = FindDifference(vec, low, mid);
    int right = FindDifference(vec, mid + 1, high);

    // If a difference was already detected (indicated by -1), propagate it up
    if (left == -1 || right == -1) {
        return -1;
    }

    // If the values in both halves are the same, return that value
    if (left == right) {
        return left;
    } else {
        // If there's a difference, print the values and return -1
        cout << "Difference found: " << left << " and " << right << endl;
        return -1; // Indicates mismatch
    }
}

int main() {
    // Example input array
    vector<int> vec = {3, 3, 3, 3, 2, 3, 3, 3};

    // Call the divide and conquer function
    int result = FindDifference(vec, 0, vec.size() - 1);

    // If result is -1, there was a mismatch
    if (result == -1) {
        cout << "The array contains differences." << endl;
    } else {
        cout << "All elements are the same: " << result << endl;
    }

    return 0;
}

