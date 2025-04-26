#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<char>&vec) {
	int count = 0;
	bool CheckoneC = false;
	for(int i = 0 ; i< vec.size() ; i++){
		if(vec[i] == '*' &&  i-1>= 0 && i+1 <= vec.size()-1 &&
		vec[i-1] =='C' && vec[i+1] =='C') {
			count++ ;
			CheckoneC=false;	
		}
		else if( vec[i] == 'C' && vec[i+1] == 'C' && i+1<= vec.size() ){
			count++; 
			CheckoneC=false;	
		}
	
		else if(vec[i] == 'C' && i-1 >= 0 && i+1 <= vec.size() && vec[i+1] != 'C'){
			CheckoneC = true;
		}
	}
	if(CheckoneC){
		count++;
	}
	return count;
}

int main() {
    int n,z;
    cin>>n>>z;
    vector<vector<char>>vec(n,vector<char>(z));
    for(int i = 0 ; i< n; i++){
    	for(int j = 0 ; j < z ; j++){
    		cin>>vec[i][j];
		}
	}
	int count = 0;
    for(int i = 0 ; i< n; i++){
    	count += solve(vec[i]);	
	}
	cout<<count;
	
   /* for(int i = 0 ; i< n; i++){
    	for(int j = 0 ; j < n ; j++){
    		cout<<vec[i][j];
		}
	}*/

    return 0;
}

