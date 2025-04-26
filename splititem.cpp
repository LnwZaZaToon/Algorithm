#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> gifts(n);

    for (int i = 0; i < n; ++i) {
        cin >> gifts[i].first >> gifts[i].second;
    }

    // sort gifts by absolute difference in descending order
    sort(gifts.begin(), gifts.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return abs(a.first - a.second) > abs(b.first - b.second);
    });
    
    for(int i = 0 ; i < n ;i++){
    	cout << gifts[i].first <<" "<< gifts[i].second<<" "<<endl;
	}

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        if (sum1 < sum2) {
            sum1 += max(gifts[i].first, gifts[i].second);
            sum2 += min(gifts[i].first, gifts[i].second);
        } else {
            sum2 += max(gifts[i].first, gifts[i].second);
            sum1 += min(gifts[i].first, gifts[i].second);
        }
    }

    cout << abs(sum1 - sum2) << endl;

    return 0;
}
/*
4
3 5
7 11
8 8
2 9*/

