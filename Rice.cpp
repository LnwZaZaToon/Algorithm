#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, int>> rice(n); 
    for (int i = 0; i < n; i++) {
        double p;
        int q;
        cin >> p >> q;
        rice[i] = {p / q, q}; 
    }

    sort(rice.begin(), rice.end()); 

    int m;
    cin >> m;
    int cur = 0;

    while (m--) {
        int b;              // kilo that  person need to buy
        cin >> b;
        double sum = 0;
        if (cur >= n) {
            continue;
        }

        while (b > 0 && cur < n) {
            if (b >= rice[cur].second) {
                sum += rice[cur].first * rice[cur].second;
                b -= rice[cur].second;
                rice[cur].second = 0;
                cur++; 
            } else {
                sum += rice[cur].first * b;
                rice[cur].second -= b;
                b = 0; 
            }
        }

        cout << fixed << setprecision(3) << sum << '\n';
    }

    return 0;
}

