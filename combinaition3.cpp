#include <bits/stdc++.h>
using namespace std;

void Combination(vector<int>& chosen, int start, int n, int k) {
    if (chosen.size() == k) {
        for (int num : chosen) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        chosen.push_back(i);
        Combination(chosen, i + 1, n, k);
        chosen.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> chosen;
    Combination(chosen, 1, n, k);

    return 0;
}

