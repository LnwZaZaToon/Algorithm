#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Word {
    string text;
    int frequency;
};

bool compare(const Word &a, const Word &b) {
    if (a.frequency != b.frequency) {
        return a.frequency < b.frequency; // ?????????????????
    }
    if (a.text.length() != b.text.length()) {
        return a.text.length() < b.text.length(); // ?????????????????????
    }
    return a.text < b.text; // ????? A-Z
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<string, int> wordCount;
        
        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;
            wordCount[word]++;
        }
        
        vector<Word> words;
        for (const auto &entry : wordCount) {
            words.push_back({entry.first, entry.second});
        }
        
        sort(words.begin(), words.end(), compare);
        
        for (const auto &w : words) {
            cout << w.frequency << " " << w.text << "\n";
        }
    }
    return 0;
}

