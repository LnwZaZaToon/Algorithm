#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int end;
    int duration;
};

bool compareDuration(const Activity &a, const Activity &b) {
	if(a.duration == b.duration ){
		return a.start <b.start;
	}
    return a.duration > b.duration;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start >> activities[i].end;
        activities[i].duration = activities[i].end - activities[i].start;
    }
    
    sort(activities.begin(), activities.end(), compareDuration);

   for(int i = 0 ; i< n ; i++){
    	cout<<activities[i].start <<" "<< activities[i].end<< " "<<endl;
	}
    vector<int> roomEndTime(k, 0); 

    int count = 0;
    for (const auto &activity : activities) {
        for (int i = 0; i < k; ++i) {
            if (roomEndTime[i] <= activity.start) {
                roomEndTime[i] = activity.end;
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}
