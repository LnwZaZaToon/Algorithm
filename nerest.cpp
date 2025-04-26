#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findClosestIndex(const vector<int> &arr, int target) {
    int closestIndex = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (abs(arr[i] - target) < abs(arr[closestIndex] - target)) {
            closestIndex = i;
        }
    }
    return closestIndex;
}

// Function to find the k nearest elements to M
void K_nearest(vector<int> A, int M, int k) {
    sort(A.begin(), A.end()); // Sort the array
    int i = findClosestIndex(A, M);
    int left = i - 1;
    int right = i;


    while (right - left - 1 < k) {
        if (left < 0) { 
            ++right;
        } else if (right >= A.size()) {
            --left;
        } else if (abs(A[left] - M) > abs(A[right] - M)) {
            ++right;
        } else {
            --left;
        }
        cout<<left<<" "<<right<<endl;
    }


    for (int j = left + 1; j < right; ++j) {
        cout << A[j] << " ";
    }
    cout << endl;
}

// Main function for testing
int main() {
    vector<int> A = {10, 12, 15, 17, 18, 20, 25};
    int M = 16; // Target value
    int k = 4; // Number of nearest items

    K_nearest(A, M, k);

    return 0;
}

