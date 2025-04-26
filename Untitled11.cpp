#include<bits/stdc++.h>
using namespace std;

class times {
public:
    double start;
    double end;
};

bool compare(const times &a, const times &b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<times> vec(n);

    // Input the start and end times for each train
    for (int i = 0; i < n; i++) {
        cin >> vec[i].start >> vec[i].end;
    }

    // Sort trains by their start times, and by end times if start times are equal
    sort(vec.begin(), vec.end(), compare);

    // Min-heap to track the earliest platform end times
    priority_queue<double, vector<double>, greater<double>> minHeap;

    // Allocate platform for the first train
    minHeap.push(vec[0].end);

    // Iterate over the rest of the trains
    for (int i = 1; i < n; i++) {
        double start = vec[i].start;
        double end = vec[i].end;

        // If the platform with the earliest end time is free, reuse it
        if (minHeap.top() <= start) {
            minHeap.pop();  // Remove the platform that gets reused
        }

        // Add the current train's end time to the priority queue (either reuse or new platform)
        minHeap.push(end);
    }

    // The size of the priority queue is the number of platforms required
    cout << minHeap.size() << endl;

    return 0;
}

