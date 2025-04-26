#include<iostream>
#include<vector>
using namespace std;

int Median(vector<int> & vec, int low, int high) {
    int mid = (low + high) / 2;
    
    if (vec[low] > vec[high]) {
        swap(vec[low], vec[high]);
    }
    if (vec[low] > vec[mid]) {
        swap(vec[mid], vec[low]);
    }
    if (vec[high] < vec[mid]) {
        swap(vec[mid], vec[high]);
    }
    
    // After sorting low, mid, and high, swap the pivot element with the high position
    swap(vec[mid], vec[high]);
    return vec[high];  // Return pivot value
}

int partition(vector<int> & vec, int low, int high) {
    int pivot = Median(vec, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[j], vec[i]);
        }
    }

    swap(vec[i + 1], vec[high]);
    cout<<i+2<<" ";
    return i + 1;
}

void QuickSort(vector<int> & vec, int low, int high) {
    if (low < high) {
        int par = partition(vec, low, high);
        QuickSort(vec, low, par - 1);
        QuickSort(vec, par + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    QuickSort(vec, 0, vec.size() - 1);

    // Output the sorted array
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    
    return 0;
}

