#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Room {
public:
    int time;
    char type;
};

bool compare(const Room& a, const Room& b) {
    if (a.time == b.time)
        return a.type == 'e'; // 'e' should come before 'x' if times are equal
    return a.time < b.time;
}

void findMaxGuests(vector<int> vec1, vector<int> vec2, int n) {
    vector<Room> room;
    for (int i = 0; i < n; i++) {
        room.push_back({vec1[i], 'e'});  // 'e' for entry
        room.push_back({vec2[i], 'x'});  // 'x' for exit
    }
    
    sort(room.begin(), room.end(), compare);

    int count = 0;
    int maxPeople = 0;
    int start = 0;
    int end = 0;
    bool isOverlap = false;  // Flag to track if overlap occurs

    // Processing the events
    for (int i = 0; i < room.size(); i++) {
        if (room[i].type == 'e') {
            count++;  // Guest enters
            if (count > maxPeople) {
                maxPeople = count;
                start = room[i].time;
                isOverlap = false;  // New max found, reset overlap flag
            }
        } 
        else if (room[i].type == 'x') {
            if (count == maxPeople) {
                end = room[i].time;
                isOverlap = true;  // Overlap happens, mark it
            }
            count--;  // Guest exits
        }
    }

    // If there's no overlap, print the first interval
    if (!isOverlap) {
        cout << start << " " << start + 1 << " " << maxPeople << endl; // print first interval
    } 
    else {
        cout << start << " " << end << " " << maxPeople << endl;  // print the overlapping interval
    }
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
    
    findMaxGuests(A, B, n);
    return 0;
}

