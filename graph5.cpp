#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<char>>& vec, int xStart, int yStart, char targetColor, char newColor) {
    vector<vector<bool>> visited(vec.size(), vector<bool>(vec[0].size(), false));
    vector<int> distX = {1, -1, 0, 0};
    vector<int> distY = {0, 0, 1, -1};
    
    queue<pair<int, int>> qq;
    qq.push({xStart, yStart});
    visited[xStart][yStart] = true;
    vec[xStart][yStart] = newColor; 
    int count = 1; 
    
    while (!qq.empty()) {
        int x = qq.front().first;
        int y = qq.front().second;
        qq.pop();
        
        for (int i = 0; i < 4; i++) {
            int NewX = x + distX[i];
            int NewY = y + distY[i];
            if (NewX < 0 || NewY < 0 || NewX >= vec.size() || NewY >= vec[0].size()) {
                continue;
            }
            if (vec[NewX][NewY] == targetColor && !visited[NewX][NewY]) {
                qq.push({NewX, NewY});
                visited[NewX][NewY] = true;
                vec[NewX][NewY] = newColor; 
                count++;
            }
        }
    }
    cout << count << endl; 
}

int main() {
    int row, col;
    cin >> row >> col;
    
    vector<vector<char>> vec(row, vector<char>(col));
    
 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> vec[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    x--;
    y--;
    
 
    char targetColor = vec[x][y];
    char newColor = 'G'; 
    
    BFS(vec, x, y, targetColor, newColor);
    
    return 0;
}

