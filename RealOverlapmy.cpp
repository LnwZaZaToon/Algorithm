#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Room{
public:
	int time;
	char type;
};

bool compare(const Room& a, const Room& b) {
    if (a.time == b.time)
        return a.type == 'e'; 
    return a.time < b.time;
}

void findMaxGuests(vector<int> vec1, vector<int> vec2, int n){
	vector<Room>room;
	for(int i = 0 ; i< n ;i++){
		room.push_back({vec1[i],'e'});
		room.push_back({vec2[i],'x'});
	}
	sort(room.begin(),room.end(),compare);
	
	int count = 0;
	int maxPeople = 0;
	int start = 0;
	int end = 0;
	

	int flag = false;
	for(int i = 0 ; i< room.size() ;i++){
		if(room[i].type == 'e'){
			count++;
			if(count > maxPeople){
				maxPeople = count;
				start =  room[i].time;
				end = room[i].time;
				flag = true;
			}
		}
		else{
			if(count == maxPeople && flag){
				end = room[i].time;
			}
			else if(count < maxPeople){
				flag =false;
			}
			
			count--;
		}
	}
	cout << start << " " << end <<" "<< maxPeople;
}

int main()
{
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

