#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    int dp[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (i==0 && j==0) { //???????????????
                dp[i][j] = arr[0][0];
            }
            else if (i == 0) { //??????????????
                dp[i][j] = arr[i][j] + dp[i][j-1];
            }
            else if (j == 0) { //????????????????
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else {
                dp[i][j] = max(arr[i][j]+dp[i-1][j], arr[i][j]+dp[i][j-1]);
            }
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
           cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}
