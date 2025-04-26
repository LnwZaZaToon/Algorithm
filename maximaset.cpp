#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    // Comparator for lexicographic sorting (by x first, then by y)
    bool operator<(const Point& p) const {
        return (x < p.x) || (x == p.x && y < p.y);
    }
    
    // Function to check if one point dominates another
    bool dominates(const Point& p) const {
        return x <= p.x && y <= p.y;
    }
};

// Recursive function to find the Maxima Set
vector<Point> maximaSet(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) {
        return points;  // Base case: if 1 or 0 points, return as is
    }

    // Step 1: Sort points lexicographically (by x, then by y)
    sort(points.begin(), points.end());

    // Step 2: Divide the points into L and G
    int mid = n / 2;
    vector<Point> L(points.begin(), points.begin() + mid);
    vector<Point> G(points.begin() + mid, points.end());

    // Step 3: Recursively find maxima in both sets
    vector<Point> M1 = maximaSet(L);
    vector<Point> M2 = maximaSet(G);

    // Step 4: Find the lexicographically smallest point in M2 (q)
    Point q = M2.front();  // Since M2 is sorted, the first element is the smallest

    // Step 5: Remove dominated points from M1
    vector<Point> result;
    for (const Point& r : M1) {
        if (!r.dominates(q)) {
            result.push_back(r);  // Keep points that are not dominated by q
        }
    }

    // Step 6: Return the union of M1 and M2
    result.insert(result.end(), M2.begin(), M2.end());
    return result;
}

int main() {
    vector<Point> points = {
        {1, 4}, {2, 6}, {3, 1}, {4, 5}, {6, 9}, {7, 2}, {8, 6}, {9, 3}
    };
    vector<Point> maxSet = maximaSet(points);  
    cout << "Maxima Set: " << endl;
    for (const Point& p : maxSet) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}

