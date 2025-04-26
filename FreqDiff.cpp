#include<iostream>
#include<vector>
#include<climits>
using namespace std;


long long int Check(vector<long long int>& vec) {
    long long int large = vec[0];
    for (long long int i = 0; i < vec.size(); i++) {
        large = max(large, vec[i]);
    }

    vector<long long int> vec2(large + 1, 0);
    for (int i = 0; i < vec.size(); i++) {
        vec2[vec[i]]++;
    }

    long long int vec2max = LLONG_MIN;
    long long int vec2min = LLONG_MAX;
    for (long long int i = 0; i < vec2.size(); i++) {
        if (vec2[i] != 0) {
            vec2max = max(vec2max, vec2[i]);
            vec2min = min(vec2min, vec2[i]);
        }
    }
    return vec2max - vec2min;
}



int main(){
	long long int n;
	cin>>n;
	
	vector<long long int>vec(n);
	for(long long int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	cout<<Check(vec);
	return 0;
}
