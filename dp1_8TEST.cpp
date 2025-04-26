#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxItems(int n, int k, vector<int>& prices, vector<vector<int>>& dp, int i, int remaining) {
    if (i == n) return 0;
    if (dp[i][remaining] != -1) return dp[i][remaining];
    
    // ??????????????????????????
    int result = maxItems(n, k, prices, dp, i + 1, remaining);
    
    // ??????????????????????? (??????????????)
    if (prices[i] <= remaining) {
        result = max(result, 1 + maxItems(n, k, prices, dp, i + 1, remaining - prices[i]));
    }

    dp[i][remaining] = result;
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // ?????????????????????? dp ?????
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    
    cout << maxItems(n, k, prices, dp, 0, k) << endl;

    return 0;
}

