#include <iostream>
#include <vector>
using namespace std;

int maxItems(int k, vector<int>& price) {
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= k; w++) {
            if (price[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - price[i - 1]] + 1);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= k; w++) {
        	cout<<dp[i][w]<<" ";
		}
		cout<<endl;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> price(n);
    
    for (int i = 0; i < n; i++)
        cin >> price[i];
    
    cout << maxItems(k, price) << endl;
    return 0;
}
