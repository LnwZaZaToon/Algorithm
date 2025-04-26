#include <iostream>
using namespace std;

void Insertion(int arr[], int n) {
    int maxShifts = 0;  // Maximum number of shifts
    int maxNumber = arr[0];  // The number causing the maximum shifts

    for (int i = 1; i < n; i++) {
        int count = 0;  // Count of shifts for the current element
        int key = arr[i];
        int j = i - 1;

        // Perform the insertion sort step
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++;  // Increment shift count
        }
        arr[j + 1] = key;

        // Update maximum shifts and the corresponding number
        if (count > maxShifts) {
            maxShifts = count;
            maxNumber = key;
        }
    }

    cout << maxNumber << endl;  // Output the number causing the maximum shifts
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Insertion(arr, n);
}
