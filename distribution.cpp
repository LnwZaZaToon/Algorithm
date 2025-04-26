#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void CountingSort(vector<int>& vec) {
    // Step 1: Find the min and max values in the array
    int MaxZ = vec[0];
    int MinZ = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        MaxZ = max(MaxZ, vec[i]);
        MinZ = min(MinZ, vec[i]);
    }
    vector<int> vec2(MaxZ - MinZ + 1, 0);
    for (int i = 0; i < vec.size(); i++) {
        vec2[vec[i] - MinZ]++;
    }
    int index = 0;
    for (int i = 0; i < vec2.size(); i++) {
        while (vec2[i] > 0) {
            vec[index++] = i + MinZ;
            vec2[i]--;
        }
    }
}

int main() {
    vector<int> vec = {5, 23, 1, 5, 4, 6, 8, 74};

    cout << "Original array: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Perform counting sort
    CountingSort(vec);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

