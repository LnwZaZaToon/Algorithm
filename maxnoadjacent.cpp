#include <iostream>
#include <vector>
using namespace std;

int maxChocolate(vector<int>& chocolates) {
    int n = chocolates.size();
    if (n == 0) return 0;
    if (n == 1) return chocolates[0];

    int prev2 = 0, prev1 = 0, current = 0;

    for (int i = 0; i < n; i++) {
        current = max(prev1, prev2 + chocolates[i]);
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int N;
    cin >> N;
    vector<int> chocolates(N);

    for (int i = 0; i < N; i++) {
        cin >> chocolates[i];
    }

    cout << maxChocolate(chocolates) << endl;
    return 0;
}

