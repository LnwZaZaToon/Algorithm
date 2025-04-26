#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum path sum from top-left to bottom-right
int generate(vector<vector<int>>& vec, int x, int y, vector<vector<int>>& dp) {
    // If out of bounds, return 0
    if(x < 0 || y < 0) {
        return 0;
    }
    
    // If already computed, return the value from dp
    if(dp[y][x] != -1) {
        return dp[y][x];
    }

    // If we are at the top-left corner, return the value of the cell
    if(x == 0 && y == 0) {
        return vec[y][x];
    }

    // Recursive calls: maximum of from left and from up
    int fromLeft =  generate(vec, x - 1, y, dp) ;
    int fromUp =  generate(vec, x, y - 1, dp) ;
    
    // Calculate the score at the current cell
    dp[y][x] = vec[y][x] + max(fromLeft, fromUp);
    
    return dp[y][x];
}

int main() {
    int n, col;
    cin >> n >> col; // Input rows and columns
    vector<vector<int>> vec(n, vector<int>(col));
    vector<vector<int>> dp(n, vector<int>(col, -1)); // Memoization table initialized to -1
    
    // Input the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < col; j++) {
            cin >> vec[i][j];
        }
    }

    // Call the generate function starting from the top-left corner
    int maxScore = generate(vec, col - 1, n - 1, dp); // Start from the bottom-right corner
    
    cout << "Maximum path sum: " << maxScore << endl;
    return 0;
}

