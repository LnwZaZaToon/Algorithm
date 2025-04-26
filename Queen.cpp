#include <bits/stdc++.h>
using namespace std;


bool IsValid(vector<vector<char>>& vec, int row, int col) {
    // Check the same column for another Queen
    for (int i = 0; i < row; i++) {
        if (vec[i][col] == 'Q') {
            return false;
        }
    }
    
    // Check the diagonal (top-left to bottom-right)
    for (int i = 0; i < row; i++) {
        if (col - (row - i) >= 0 && vec[i][col - (row - i)] == 'Q') {
            return false;
        }
    }
    
    // Check the diagonal (top-right to bottom-left)
    for (int i = 0; i < row; i++) {
        if (col + (row - i) < vec.size() && vec[i][col + (row - i)] == 'Q') {
            return false;
        }
    }
    
    return true;
}



void Queen(vector<vector<char>>& vec, int start) {
	if(start == vec.size()){
		for(int i = 0;  i < vec.size() ; i++ ){
			for(int j = 0 ; j  < vec[i].size() ;j++){
				cout<< vec[i][j]<<" ";
			}
			cout<<endl;
			
		}
		cout<<"-------------------------------------------------------------"<<endl;
		return;
	}
    
    
    
    for(int i = 0 ; i < vec.size() ; i++){
    	if(IsValid(vec,start,i)){
    		vec[start][i] = 'Q';
    		Queen(vec, start+1);
			vec[start][i] = '.';
		}
	}
}

int main() {
    int n;
    cin >> n ;
    vector<vector<char>>vec(n, vector<char>(n , '.'));
    Queen(vec, 0);
    
    return 0;
}

