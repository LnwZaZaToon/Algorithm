#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<char>> &vec , int row , int col){
	
	for(int i = 0 ; i < col ; i++){
		if(vec[row][i] == 'Q'){
			return false;
		}
	}
	
	for(int i = 0 ; i < row ; i++){
		if(vec[i][col] == 'Q'){
			return false;
		}
	}
	
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (vec[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < vec.size(); i--, j++) {
        if (vec[i][j] == 'Q') return false;
    }
	return true;
	
}



void Backtracking(vector<vector<char>> &vec,int row) {
	if(row == vec.size()) {
		for(int i = 0 ; i < vec.size()  ; i++){
			for(int j = 0 ; j < vec[i].size() ; j++){
				cout<< vec[i][j] << " ";
			}
			cout<<endl;
		}
		cout<<"--------------"<<endl;
		return ;
	}
	
	
	for(int i  = 0; i < vec.size() ; i++){
		if(isSafe(vec,row,i)){
			vec[row][i] = 'Q';
			Backtracking(vec,row+1 );
			vec[row][i] = '.';
		}
	}
	
	
	
}



int main(){
	int n = 4;
	vector<vector<char>> vec(n , vector<char>(n,'.'));
	Backtracking(vec,0);
	
	return 0;
}
