#include<bits/stdc++.h>
using namespace std;

void Test(vector<int>& vec, int start, int n) {
    if(start == n) {
        // Print the current subset (subset of indices)
        bool first = true;
        for(int i = 0; i < n; i++) {
            if(vec[i] == 1) {
                if(!first) {
                    cout << " ";
                }
                cout << i;  // Print the index itself
                first = false;
            }
        }
        cout << endl;
        return;
    }

    // Include the current element (set it to 1)
    vec[start] = 1;
    Test(vec, start + 1, n);
    
    // Exclude the current element (set it to 0)
    vec[start] = 0;
    Test(vec, start + 1, n);
}

int main() {
    int n = 3;
    vector<int> vec(n, 0);  // Initialize with 0's (none of the elements are included initially)
    Test(vec, 0, n);
    
    return 0;
}

