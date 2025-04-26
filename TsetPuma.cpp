// C++ code for the above approach:
#include <bits/stdc++.h>

using namespace std;

// Function to right rotate the segement
// arr[i....j] of arr
void RightRotate(char arr[], int i, int j)
{
	char temp = arr[j];
	for (int k = j; k > i; k--) {
		arr[k] = arr[k - 1];
	}
	arr[i] = temp;
}

// Function to Left rotate the segement
// arr[i....j] of arr
void LeftRotate(char arr[], int i, int j)
{
	char temp = arr[i];
	for (int k = i; k < j; k++) {
		arr[k] = arr[k + 1];
	}
	arr[j] = temp;
}
void PrintPermutations(char arr[], int i, int n)
{

	// Base case if i reaches end of the
	// array and there is no element
	// to swap with
	if (i == n - 1) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	// If do not rotate any segement
	// starting from i+1th index
	PrintPermutations(arr, i + 1, n);

	// If we rotate segement then we can have
	// rotation of segement arr[i....j]
	for (int j = i + 1; j < n; j++) {
		RightRotate(arr, i, j);
		PrintPermutations(arr, i + 1, n);
		LeftRotate(arr, i, j);
	}
}

/// Drivers code
int main()
{
	char arr[] = { 'E'  , 'X' , 'A','B' };
	int N = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + N);

	// Function Call
	cout << "Permutations are below" << endl;
	PrintPermutations(arr, 0, N);
	return 0;
}

