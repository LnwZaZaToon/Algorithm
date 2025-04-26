#include <bits/stdc++.h>
using namespace std;

class Times {
public:
    double start;
    double end;
    double duration;
};

bool compare(const Times &a, const Times &b) {
    if (a.duration == b.duration) {
        return a.start > b.start;
    }
    return a.duration > b.duration;
}

int main() {
    int n;
    cin >> n;
    vector<Times> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i].start >> vec[i].end;
        vec[i].duration = vec[i].end - vec[i].start;
    }

    sort(vec.begin(), vec.end(), compare);

    priority_queue<double, vector<double>, greater<double>> pq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() <= vec[i].start) {
            pq.pop();
        pq.push(vec[i].end);
       // cout<<pq.size();
    }
	}

    cout << count;

    return 0;

}

