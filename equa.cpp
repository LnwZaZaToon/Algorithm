#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to perform arithmetic operations
int operate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}

// Recursive function to compute all possible results of an expression with different parentheses placements
vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            // Divide the input into two parts and solve recursively
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            
            // Combine results from left and right parts
            for (int l : left) {
                for (int r : right) {
                    result.push_back(operate(l, r, c));
                }
            }
        }
    }
    // If the result is empty, convert the input to an integer and add to the result
    if (result.empty()) {
        result.push_back(stoi(input));
    }
    return result;
}

int main() {
    vector<string> inputs = {"2-1-1", "2*3-4+5"};
    
    for (const string& input : inputs) {
        vector<int> results = diffWaysToCompute(input);
        
        cout << "All possible results for \"" << input << "\":\n";
        for (int res : results) {
            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}

