#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function to divide the array around the pivot
int partition(int left, int right, vector<int>& A) {
    int pivot = A[right]; // Use the last element as the pivot
    int up = left;
    int down = right - 1;

    while (true) {
        // Move 'up' to the right while elements are less than the pivot
        while (up <= down && A[up] < pivot) up++;

        // Move 'down' to the left while elements are greater than the pivot
        while (down >= up && A[down] > pivot) down--;

        // If 'up' and 'down' cross, break the loop
        if (up >= down) break;

        // Swap the elements at 'up' and 'down'
        swap(A[up], A[down]);
        
    }

    // Move the pivot into its correct position
 /*   swap(A[up], A[right]);
    for (int i = 0; i < 8; i++) {
        cout << A[i] << " ";
    }*/
    cout<<endl;
    return up; // Return the pivot index
}

// QuickSort function to recursively sort the array
void quickSort(int left, int right, vector<int>& A) {
    if (left >= right) return; // Base case: no elements to sort

    // Partition the array and get the pivot index
    int pivotIndex = partition(left, right, A);

    // Recursively apply quickSort to the subarrays
    quickSort(left, pivotIndex - 1, A);
    quickSort(pivotIndex + 1, right, A);
}

int main() {
    int n = 8;
    vector<int> A = {2,5,1,7,9,11,12,10/*16,25,2,66,36,9,12,54*/};

    // Perform the quickSort
    quickSort(0, n - 1, A);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

