#include<iostream>
#include<vector>
using namespace std;
vector<int> CountSort(vector<int>&vec) {
	int large = *vec.begin();
	for(int i = 0 ; i< vec.size() ;i++){
		large = max(large,vec[i]);
	}
	vector<int>vec2(large+1 , 0);
	
	for(int i = 0 ; i< vec.size() ;i++){
		vec2[vec[i]]++;
	}
	for(int i = 1 ; i< vec2.size() ;i++){
		vec2[i] += vec2[i-1];
	}
	vector<int>vec3(vec.size());
	for(int i = vec.size()-1; i>=0 ;i-- ){
		vec3[vec2[vec[i]]-1] = vec[i];
		vec2[vec[i]]--;
	}
	return vec3;
	
}




int main(){
	
    // Input array
    vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };

    // Output array
    vector<int> outputArray = CountSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";

    return 0;
}
