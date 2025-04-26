#include <iostream>
#include <vector>
using namespace std;

void Check(const vector<int>& vec) {
    int max_streak = 0; // Maximum consecutive days
    int current_streak = 0; // Current consecutive days

    for (int hours : vec) {
        if (hours > 6) {
            current_streak++;
            max_streak = max(max_streak, current_streak);
        } else {
            current_streak = 0; // Reset streak if hours <= 6
        }
    }

    cout << max_streak << endl;
}

int main() {
    long int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    Check(vec);

    return 0;
}

