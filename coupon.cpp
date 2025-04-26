#include<bits/stdc++.h>
using namespace std;

void Light(vector<int>& vec, vector<int>& x, int start, int end, int k, int amount, vector<int>& selectedBooks) {
    // Base case: when we have selected 3 books
    if (selectedBooks.size() == 3) {
        if (amount <= k) {
            sort(selectedBooks.begin(), selectedBooks.end());  // Sort selected books in ascending order
            for (int price : selectedBooks) {
                cout << price << " ";
            }
            cout << endl;
            return;  // Stop after finding the first valid combination
        }
        return;
    }
    if (start == end) return;
    selectedBooks.push_back(x[start]);
    Light(vec, x, start + 1, end, k, amount + x[start], selectedBooks);
    selectedBooks.pop_back();
    Light(vec, x, start + 1, end, k, amount, selectedBooks);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> vec(n, 0);  // Vector to keep track of whether a book is selected or not
    vector<int> selectedBooks;  // To store the selected books for each valid combination

    Light(vec, x, 0, n, k, 0, selectedBooks);

    return 0;
}

