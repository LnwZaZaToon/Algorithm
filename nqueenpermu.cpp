#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printSolution(int x[],int end) {
    for (int i = 0; i < end; i++) {
        cout << x[i] << " "; 
    }
    cout << endl;
}

void permute(int x[], int start, int end) {
    if (start == end) {
        int flag = 0;
        for(int j = 1 ; j < end ; j++){
        	for(int p = 0 ; p < j ; p ++){
        		if(abs(p-j) == abs(x[p]-x[j])||(x[j] == x[p])){
        			flag = 1;
				}
			}
		}
		if(flag == 0){
			printSolution(x,end);
		}
        return;
    }

    for (int i = start; i < end; i++) {
        swap(&x[start], &x[i]);
        permute(x, start + 1, end);
        swap(&x[start], &x[i]);
    }
}

int main() {
    int n = 4;
    int X[] = {0, 1, 2, 3};
    permute(X, 0, n);

    return 0;
}
