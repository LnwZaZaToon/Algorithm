#include <iostream>
#include <vector>
using namespace std;

int main() {
    long w, h;
    cin >> h >> w;

    vector<vector<char>> vec(w, vector<char>(h));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> vec[i][j];
        }
    }
    int count = 0;

    for (int i = 0; i < w  ; i++) { // Avoid out-of-bounds
        for (int j = 0; j < h; j++) {           	
			if(vec[i][j] == 'C' && vec[i+1][j] != 'C' && i+1 != w){
				count++;
			}			
        }
    }
    

    cout << "Count: " << count << endl;

    return 0;
}

