#include<bits/stdc++.h>
using namespace std;

class Points{
public:
    int x;
    int y;
};

bool compare(const Points& a , const Points& b){
    return a.x < b.x;
}

void Merge(vector<Points>& vec, int low, int high, int mid) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<Points> A(n1), B(n2);

    for (int i = 0; i < n1; i++) {
        A[i] = vec[low + i];
    }
    for (int i = 0; i < n2; i++) {
        B[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (compare(A[i], B[j])) {
            vec[k++] = A[i++];
        } else {
            vec[k++] = B[j++];
        }
    }

    while (i < n1) {
        vec[k++] = A[i++];
    }
    while (j < n2) {
        vec[k++] = B[j++];
    }
}

int status[10000] = {1};

void Conquer(vector<Points>& vec, int low, int high, int mid) {
    int k;
    for (int i = mid + 1; i <= high; i++) {
        if (status[i] == 1) {
            k = i;
            break;
        }
    }

    for (int i = low; i <= mid; i++) {
        if (status[i] == 1 && vec[i].y < vec[k].y) {  // Change here: comparing y values
            status[i] = 0;
        }
    }
}

void Maxima(vector<Points>& vec, int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;
        Maxima(vec, low, mid);
        Maxima(vec, mid + 1, high);
        Conquer(vec, low, high, mid);
    }
}

void MergeSort(vector<Points>& vec, int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;
        MergeSort(vec, low, mid);
        MergeSort(vec, mid + 1, high);
        Merge(vec, low, high, mid);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Points> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].x >> vec[i].y;
    }

    MergeSort(vec, 0, n - 1);

    for (int i = 0; i < 10000; i++) {
        status[i] = 1; // Reset the status array
    }

    Maxima(vec, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            cout << "(" << vec[i].x << "," << vec[i].y << ") | ";
        }
    }

    return 0;
}

