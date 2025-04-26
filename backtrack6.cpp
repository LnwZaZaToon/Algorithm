#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Function to manually sort the array in ascending order
void manualSort(vector<char> &vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
}

// Recursive function to generate permutations
void Permutation(vector<char> &vec, int low, int high) {
    if (low == high) {
        for (int i = 0; i <= high; i++) {
            cout << vec[i];
        }
        cout << endl;
        return;
    }

    for (int i = low; i <= high; i++) {
        // Swap only if it's the first occurrence (to avoid duplicate swaps)
        bool shouldSwap = true;
        for (int j = low; j < i; j++) {
            if (vec[j] == vec[i]) {
                shouldSwap = false;
                break;
            }
        }
        if (!shouldSwap) continue;

        swap(vec[i], vec[low]);
        Permutation(vec, low + 1, high);
        swap(vec[i], vec[low]); // Backtrack
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Step 1: Sort the input to ensure lexicographic order
    manualSort(vec);

    // Step 2: Generate permutations
    Permutation(vec, 0, vec.size() - 1);

    return 0;
}

