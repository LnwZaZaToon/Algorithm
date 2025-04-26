#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
using namespace std;

// Partition function for Quickselect
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // Choose the rightmost element as the pivot
    int i = left;            // Index for the smaller element

    for (int j = left; j < right; ++j) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    // Place the pivot in its correct position
    swap(nums[i], nums[right]);
    return i;
}

// Quickselect function to find the k-th smallest element
int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) { // Base case: single element
        return nums[left];
    }

    // Partition the array and get the pivot index
    int pivotIndex = partition(nums, left, right);

    // Check the position of the pivot with respect to k
    if (pivotIndex == k) {
        return nums[pivotIndex]; // Found the k-th smallest element
    } else if (pivotIndex > k) {
        // Recur on the left part of the array
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        // Recur on the right part of the array
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

int findKthSmallest(vector<int>& nums, int k) {
    if (k > 0 && k <= nums.size()) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1); // k-1 for 0-based indexing
    } else {
        return -1; // Invalid k
    }
}

int main() {
    vector<int> arr = {7, 2, 5, 3, 8, 1, 4};
    int k = 3; // Find the 3rd smallest element

    int thirdLeast = findKthSmallest(arr, k);
    if (thirdLeast != -1) {
        cout << "The " << k << "rd smallest number is: " << thirdLeast << endl;
    } else {
        cout << "Invalid k value!" << endl;
    }

    return 0;
}

