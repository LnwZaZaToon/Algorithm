#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec1(n);
    vector<int> vec2(n);

    for (int i = 0; i < n; i++) {
        cin >> vec1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> vec2[i];
    }

    int count = 0;
    int start = vec1[0];
    int end = vec2[0];

    for (int i = 0; i < n; i++) {
        if (vec1[i] >= start && vec2[i] <= end) {
            start = vec1[i];
            end = vec2[i];
            count++;
        }
   		else if(vec1[i] <= end && vec1[i]>=start && vec2[i]>=end){
   			start = vec1[i];
   			count++;
		   }
		else if(vec1[i] <= start && vec2[i]>= start && vec2[i]<=end){
			end = vec2[i];
			count++;
		}
    }

    cout << start << " " << end << " " << count;
    return 0;
}

