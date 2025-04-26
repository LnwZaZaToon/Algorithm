#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Event {
    int time;
    char type; 
};

void findMaxStudentsInRoom(int n, vector<int>& A, vector<int>& B) {
    vector<Event> events;

    for (int i = 0; i < n; i++) {
        events.push_back({A[i], 'e'});
        events.push_back({B[i], 'x'}); 
    }
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time == b.time)
            return a.type == 'e'; 
        return a.time < b.time;
    });

    int currentCount = 0;
    int maxCount = 0;
    int bestTimeStart = 0;
    int bestTimeEnd = 0;

    for (const auto& event : events) {
        if (event.type == 'e') { 
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
                bestTimeStart = event.time;
                bestTimeEnd = event.time; 
            }
        } else { 
            if (currentCount == maxCount) {
                bestTimeEnd = event.time; 
            }
            currentCount--;
        }
    }

    cout << bestTimeStart << " " << bestTimeEnd << " " << maxCount << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    findMaxStudentsInRoom(n, A, B);

    return 0;
}

