#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int start, end;
    bool operator<(const Line &other) const {
        if (start == other.start) return end < other.end;
        return start < other.start;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Line> lines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lines[i].start >> lines[i].end;
    }
    
    int xa, xb;
    cin >> xa >> xb;
    
    // ????????????????????????????? ????????????????????????????????????????
    sort(lines.begin(), lines.end());
    
    vector<Line> result;
    int currentStart = xa, currentEnd = xa;
    int i = 0;
    
    while (i < n && currentEnd < xb) {
        int bestEnd = currentEnd;
        Line bestLine = {-1, -1};
        
        while (i < n && lines[i].start <= currentEnd) {
            if (lines[i].end > bestEnd) {
                bestEnd = lines[i].end;
                bestLine = lines[i];
            }
            i++;
        }
        
        if (bestLine.start == -1) {
            cout << -1 << endl; // ????????????????????????
            return 0;
        }
        
        result.push_back(bestLine);
        currentEnd = bestEnd;
    }
    
    if (currentEnd < xb) {
        cout << -1 << endl; // ????????????????????????
    } else {
        cout << result.size() << endl;
        for (const auto &line : result) {
            cout << line.start << " " << line.end << endl;
        }
    }
    
    return 0;
}

