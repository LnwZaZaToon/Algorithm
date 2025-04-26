#include <bits/stdc++.h>
using namespace std;

vector<int> books;
int N, M;
vector<int> bestResult(3, 0);
int maxSum = 0;

void Find(vector<int>& vec, int start, int count, int sum) {
    if (count == 3) {  
        if (sum <= M && sum > maxSum) {
            maxSum = sum;
            bestResult.clear();
            for (int i = 0; i < N; i++) {
                if (vec[i] == 1) {
                    bestResult.push_back(books[i]);
                }
            }
        }
        return;
    }

    if (start >= N) return;  
    vec[start] = 1;
    Find(vec, start + 1, count + 1, sum + books[start]);

    vec[start] = 0;
    Find(vec, start + 1, count, sum);
}

int main() {
    cin >> N >> M;
    books.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> books[i];
    }

    sort(books.begin(), books.end()); 
    
    vector<int> vec(N, 0); 
    Find(vec, 0, 0, 0);

    if (maxSum > 0) {
        for (int num : bestResult) {
            cout << num << endl;
        }
    } 

    return 0;
}

