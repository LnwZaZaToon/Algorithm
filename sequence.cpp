#include <iostream>
#include <string>
using namespace std;

string findLongestRepeatedSubstring(const string& str) {
    int maxLength = 0;
    string longestSubstring = "";
    int currentLength = 1;

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestSubstring = str.substr(i - currentLength, currentLength);
            }
            currentLength = 1;  // Reset for the next sequence
        }
    }

    // Check at the end in case the longest sequence is at the end
    if (currentLength > maxLength) {
        longestSubstring = str.substr(str.size() - currentLength, currentLength);
    }

    return longestSubstring;
}

int main() {
    string input;
    cout << "Enter a sequence of digits: ";
    cin >> input;

    string result = findLongestRepeatedSubstring(input);

    if (!result.empty()) {
        cout << "The longest repeated substring is: " << result << endl;
    } else {
        cout << "No repeated substring found." << endl;
    }

    return 0;
}

