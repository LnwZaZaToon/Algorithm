#include <iostream>
#include <vector>
using namespace std;


int mergeAndCount(vector<int>& vec, int low, int mid, int high) {
    vector<int> left(vec.begin() + low, vec.begin() + mid + 1);
    vector<int> right(vec.begin() + mid + 1, vec.begin() + high + 1);

    int i = 0, j = 0, k = low;
    int invCount = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
            invCount += (left.size() - i); // All remaining elements in left form inversions
        }
    }

    // Add remaining elements from left and right
    while (i < left.size()) {
        vec[k++] = left[i++];
    }
    while (j < right.size()) {
        vec[k++] = right[j++];
    }

    return invCount;
}


int Count(vector<int>& vec, int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = (low + high) / 2;
    int leftCount = Count(vec, low, mid);
    int rightCount = Count(vec, mid + 1, high);
    int mergeCount = mergeAndCount(vec, low, mid, high);

    return leftCount + rightCount + mergeCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int inversionCount = Count(vec, 0, n - 1);

    cout << inversionCount << endl;

    return 0;
}

