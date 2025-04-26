// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number
// of intervals in the array A[] to
// cover the entire target interval
int minimizeSegment(vector<pair<int, int> > A,
					pair<int, int> X)
{
	// Sort the array A[] in increasing
	// order of starting point
	sort(A.begin(), A.end());

	// Insert a pair of INT_MAX to
	// prevent going out of bounds
	A.push_back({ INT_MAX, INT_MAX });

	// Stores start of current interval
	int start = X.first;

	// Stores end of current interval
	int end = X.first - 1;

	// Stores the count of intervals
	int cnt = 0;

	// Iterate over all the intervals
	for (int i = 0; i < A.size();) {

		// If starting point of current
		// index <= start
		if (A[i].first <= start) {
			end = max(A[i++].second, end);
		}
		else {

			// Update the value of start
			start = end;

			// Increment the value
			// of count
			++cnt;

			// If the target interval is
			// already covered or it is
			// not possible to move
			// then break the loop
			if (A[i].first > end
				|| end >= X.second) {
				break;
			}
		}
	}

	// If the entire target interval
	// is not covered
	if (end < X.second) {
		return -1;
	}

	// Return Answer
	return cnt;
}

// Driver Code
int main()
{
	vector<pair<int, int> > A = {
		{ 1, 2 }, { 3, 5 }, { 1, 5 }, { 2, 4 }, { 4, 5 },
		{3,6},{2,7},{7,9},{4,8},{1,3}
	};
	pair<int, int> X = { 1, 9 };
	cout << minimizeSegment(A, X);

	return 0;
}

