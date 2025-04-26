#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    const int MAX_TIME = 100001;
    vector<int> cus(MAX_TIME, 0);
    
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        
        for (int j = s; j <= e; ++j) {
            cus[j]++;
        }
    }
    
    int maxCus = 0;
    int st = 0, ent = 0;
    bool currCus = false;
    
    for (int i = 0; i < MAX_TIME; ++i) {
        if (cus[i] > maxCus) {
            maxCus = cus[i];
            st = i;
            ent = i;
            currCus = true;
        } else if (cus[i] == maxCus && currCus) {
            ent = i;
        } else if (cus[i] < maxCus) {
        	currCus = false;
		}
    }
    
    cout << st << " " << ent << " " << maxCus << endl;
    
    return 0;
}

