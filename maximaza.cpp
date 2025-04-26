#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Points{
public:
    int x;
    int y;
};

// Comparator to sort the points based on x, and if x is the same, based on y
bool compare(const Points a, const Points b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Helper function to check if point p2 is above the line formed by points p0 and p1
bool isAbove(Points p0, Points p1, Points p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) > (p1.y - p0.y) * (p2.x - p0.x);
}

// Merge function to get the maxima set (upper convex hull)
vector<Points> MaximaSet(vector<Points>& vec, int low, int high) {
    vector<Points> maxima;
    
    if (low == high) {
        maxima.push_back(vec[low]);
        return maxima;
    }
    
    int mid = (low + high) / 2;
    vector<Points> M1 = MaximaSet(vec, low, mid);
    vector<Points> M2 = MaximaSet(vec, mid + 1, high);
    
    // Merging two halves to get the upper convex hull
    int i = M1.size() - 1, j = 0;
    while (i >= 0 && j < M2.size()) {
        if (isAbove(M1[i], M2[j], M1[i])) {
            maxima.push_back(M1[i]);
            i--;
        } else {
            maxima.push_back(M2[j]);
            j++;
        }
    }
    
    // Append remaining points
    while (i >= 0) {
        maxima.push_back(M1[i]);
        i--;
    }
    
    while (j < M2.size()) {
        maxima.push_back(M2[j]);
        j++;
    }
    
    return maxima;
}

int main() {
    int n;
    cin >> n;
    vector<Points> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i].x >> vec[i].y;
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    vector<Points> maxima = MaximaSet(vec, 0, n - 1);
    
    // Output the maxima points
    cout << "Maxima Points: ";
    for (const auto& p : maxima) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
    
    return 0;
}

