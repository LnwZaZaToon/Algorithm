#include <iostream>
#include <cmath>
using namespace std;

int n = 4, x[4]; 

void printSolution() {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " "; 
    }
    cout << endl;
}

int isSafe(int k, int row) {
    for (int j = 0; j < k; j++) {
        // Check if queens are in the same column or diagonals
        if (x[j] == row || abs(x[j] - row) == abs(j - k)) {
            return 1; // Conflict found
        }
    }
    return 0;
}
void n_queen(int k) {
    if (k == n) { 
        int flag = 0;
        for(int j = 1 ; j < k ; j++){
        	for(int p = 0 ; p < j ; p ++){
        		if(abs(p-j) == abs(x[p]-x[j])||(x[j] == x[p])){
        			flag = 1;
				}
			}
			
		}
		if(flag == 0){
			printSolution();
		}
		
     
    }
    else{
    	    for (int i = 0; i < n; i++) {
        x[k] = i;
        n_queen(k + 1);
        
    }
	}
	


}

int main() {
    n_queen(0);
    return 0;
}

