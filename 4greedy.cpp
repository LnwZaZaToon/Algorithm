#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ????????????????????????????
struct Line {
    int start, end;
};

// ?????????????????????????????????????????????
bool compare(Line a, Line b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    
    vector<Line> lines(n);
    
    // ????????????? n ????
    for (int i = 0; i < n; i++) {
        cin >> lines[i].start >> lines[i].end;
    }
    
    // ????????????????????????????? (xa, xb)
    int xa, xb;
    cin >> xa >> xb;

    // ?????????????????
    sort(lines.begin(), lines.end(), compare);

    int currentEnd = xa; // ?????????????????????
    int index = 0, count = 0;
    vector<Line> result;

    // ??? Greedy algorithm ??????????????????????????????????????????
    while (currentEnd < xb) {
        int farthest = currentEnd;
        Line bestLine = {-1, -1};

        // ???????????????????????????????? currentEnd ????????????????
        while (index < n && lines[index].start <= currentEnd) {
            if (lines[index].end > farthest) {
                farthest = lines[index].end;
                bestLine = lines[index];
            }
            index++;
        }

        // ??????????????????????? ???????????????????????????
        if (farthest == currentEnd) {
            cout << -1 << endl;
            return 0;
        }

        // ????????????????????????????
        result.push_back(bestLine);
        count++;
        currentEnd = farthest;
    }

    // ???????????
    cout << count << endl;
    for (auto line : result) {
        cout << line.start << " " << line.end << endl;
    }

    return 0;
}

