#include <bits/stdc++.h>
using namespace std;

class Times{
public:
	int start;
	int end;
	int duration;
};

bool compare(const Times &a , const Times &b){
	
	if(a.duration == b.duration ){
		return a.start < b.start;
	}
	return a.duration > b.duration;
}


int main() {
    int n ,k;
    cin>> n >> k;
    vector<Times>vec(n);
    for(int i = 0 ; i< n ;i++){
    	int start , end ;
    	cin>> start >> end;
    	vec[i].start = start;
    	vec[i].end = end;
    	vec[i].duration = end-start;
	}
	sort(vec.begin() , vec.end() ,  compare);
    
    for(int i = 0 ; i< n;  i++){
    	cout<<vec[i].start <<" "<<vec[i].end<<" "<<endl;
	}
   	priority_queue<int, vector<int>, greater<int>> roomEndTime(k,0);
    
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int earliestEndTime = roomEndTime.top();
        	cout<<earliestEndTime<<" ";
        if(earliestEndTime <= vec[i].start) {
            roomEndTime.pop(); 
            roomEndTime.push(vec[i].end); 
            count++; 
        }
    }
    
    cout << count << endl;
    
    return 0;
}
/*
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
*/
