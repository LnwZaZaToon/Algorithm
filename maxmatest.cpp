#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
public:
	int x;
	int y;
};
vector<Point> maximaSet(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) {
        return points; 
    }

    sort(points.begin(), points.end());
    int mid = n / 2;
    vector<Point> L(points.begin(), points.begin() + mid);
    vector<Point> G(points.begin() + mid, points.end());

    vector<Point> M1 = maximaSet(L);
    vector<Point> M2 = maximaSet(G);

    Point q = M2.front();  

    vector<Point> result;
    for (const Point& r : M1) {
        if (!r.dominates(q)) {
            result.push_back(r);  
        }
    }

    // Step 6: Return the union of M1 and M2
    result.insert(result.end(), M2.begin(), M2.end());
    return result;
}
bool compare(const Point a , const Point b ){
	return a.x < b.x;
}

int main() {
    vector<Point> points = {
        {1, 4}, {2, 6}, {3, 1}, {4, 5}, {6, 9}, {7, 2}, {8, 6}, {9, 3}
    };
    sort(points.begin(), points.end(),compare);
    
    vector<Point> maxSet = maximaSet(points);  
    cout << "Maxima Set: " << endl;
    
    for (const Point& p : maxSet) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}

