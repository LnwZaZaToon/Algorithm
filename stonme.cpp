#include <bits/stdc++.h>

using namespace std;

int ar[10000];

int stone(int l, int r) {
    if (r - l + 1 == 1) {  // base case: only one element, it is the distinct one
        return l;
    } else {
        int mid = (l + r) / 2;
        int first = stone(l, mid);  // Find the distinct stone in the first half
        int second = stone(mid + 1, r);  // Find the distinct stone in the second half
        
        // Compare the two results
        if (ar[first] != ar[second]) {
            return ar[first] != ar[mid] ? first : second;
        } else {
            // If both are equal, then the distinct stone is somewhere in the subarray
            return ar[first] != ar[mid] ? first : second;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    cout << stone(0, n - 1);
    return 0;
}

