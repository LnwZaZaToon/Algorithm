#include <bits/stdc++.h>
using namespace std;

void Subset(vector<int>& vec, int start, int k, vector<int>& result, int count) {
    if (count == k) {  // Base case: Found a valid subset
        for (int i = 0; i < vec.size(); i++) {
         
                cout << vec[i] << " ";
            
        }
        cout << endl;
        return;
    }

    if (start == vec.size() || count > k) {  // Stop when out of bounds or exceeding sum
        return;
    }

    // Include current element
    vec[start] = 1;
    Subset(vec, start + 1, k, result, count + result[start]);

    // Exclude current element
    vec[start] = 0;
    Subset(vec, start + 1, k, result, count);
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> result(n);  // Stores actual numbers
    vector<int> vec(n, 0);  // Binary mask (0 = not included, 1 = included)

    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }

    Subset(vec, 0, k, result, 0);
    
    return 0;
}

