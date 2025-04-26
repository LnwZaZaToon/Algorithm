#include <iostream>
#include <algorithm> // For std::min
using namespace std;

int Divide(int arr[], int start, int end) {
    if (start > end) {
        return INT_MAX; // Return a very large value to ensure it's ignored in min calculation
    } else if (start == end) {
        return arr[start]; // Base case: single element
    }

    int offset = start + (end - start) / 3;          // First third
    int offset2 = start + 2 * (end - start) / 3;     // Second third

    int left = Divide(arr, start, offset);          // Left part
    int middle = Divide(arr, offset + 1, offset2);  // Middle part
    int right = Divide(arr, offset2 + 1, end);      // Right part

    return min({left, middle, right}); // Find minimum of three values
}

int main() {
    int arr[] = {56, 156, 4, 68, 6, 385, 46};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Minimum value: " << Divide(arr, 0, n - 1) << endl;
    return 0;
}

