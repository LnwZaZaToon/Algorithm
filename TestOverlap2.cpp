#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqCounter;
        for (int num : nums) {
            freqCounter[num]++;
        }

        int maxFrequency = 0;
        int minFrequency = 1000001;
        for (const auto& entry : freqCounter) {
            maxFrequency = max(maxFrequency, entry.second);
            minFrequency = min(minFrequency, entry.second);
        }
        int totalFrequency = maxFrequency-minFrequency;

        return totalFrequency;
    }



int main(){
	int n;
	cin>>n;
	
	vector<int>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i];
	}
	cout<<maxFrequencyElements(vec);
	return 0;
}
