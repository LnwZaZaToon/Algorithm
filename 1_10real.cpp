#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;


    const int MAX_HOUR = 100001;
    vector<int> timeline(MAX_HOUR, 0);

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        timeline[A]++;     
        timeline[B + 1]--;  
    }


    int maxCustomers = 0, currentCustomers = 0;
    int startHour = 0, endHour = 0;
    int tempStartHour = 0;

    for (int hour = 0; hour < MAX_HOUR; ++hour) {
        currentCustomers += timeline[hour];

        if (currentCustomers > maxCustomers) {
            maxCustomers = currentCustomers;
            startHour = tempStartHour;
            endHour = hour;
        }

        if (currentCustomers == 0) {
            tempStartHour = hour + 1; 
        }
    }

    cout << startHour << " " << endHour - 1 << " " << maxCustomers << endl;

    return 0;
}

