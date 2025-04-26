#include<bits/stdc++.h>
using namespace std;

int TopDown(vector<int>& vec, int j, int k, vector<vector<int>>& memo) {
 
    if (k == 0) return 0; 
    if (j >= vec.size()) return -1;
    if (k < 0) return -1; 


    if (memo[j][k] != -1) return memo[j][k];

    int count = -1;


    for (int i = j; i < vec.size(); i++) {
        if (k >= vec[i]) {
            int take = TopDown(vec, i + 1, k - vec[i], memo);
            if (take != -1) { 
                count = max(count, take + 1);
            }
        }
    }


    return memo[j][k] = count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));


    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }


    int result = TopDown(vec, 0, k, memo);
    cout << (result == -1 ? 0 : result) << endl;

 
    for (int i = 0; i < memo.size(); i++) {
        for (int j = 0; j < memo[i].size(); j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
