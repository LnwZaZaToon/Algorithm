#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int X[], int start, int end) {
    if (start == end) {
        for (int i = 0; i < end; i++) {
            printf("%d ", X[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < end; i++) {
    	sort(X+i , X+end);
        swap(&X[start], &X[i]);
        permute(X, start + 1, end);
        swap(&X[start], &X[i]);
    }
}

int main() {
    int n = 4;
    int X[] = { 1, 2, 3,4};
    sort(X , X+n);

    permute(X,0, n);

    return 0;
}
