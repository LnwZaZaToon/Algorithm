#include <iostream>
#include <vector>
using namespace std;

void permu(vector<int>& vec, int low, vector<vector<int>>& result, vector<int>& subset) {
    result.push_back(subset);  // Store the current subset

    for (int i = low; i < vec.size(); i++) {
        subset.push_back(vec[i]);  // Include current element
        permu(vec, i + 1, result, subset);  // Recurse with next index
        subset.pop_back();  // Backtrack to explore other possibilities
    }
}

int main() {
    int n = 3;
    vector<int> vec = {1, 2, 3};	
    vector<vector<int>> result;  // Store all subsets
    vector<int> subset;  // Temporary subset

    permu(vec, 0, result, subset);

    // Print all subsets
    for (const auto& s : result) {
        cout << "{ ";
        for (int num : s) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

