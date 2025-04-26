#include <bits/stdc++.h>
using namespace std;



void leftRotate(vector<char>& vec , int i , int j){
	char temp = vec[i];
	for(int z = i ; z < j ;z++){
		vec[z] = vec[z+1];
	}
	vec[j] = temp;
}
void rightRotate(vector<char>& vec , int i , int j){
	int temp = vec[j];
	for(int z = j ; z> i ;z--){
		vec[z] = vec[z-1];
	}
	vec[i] = temp;
}



void Permutation(vector<char>& vec , int start , int end){
	if(start == end-1){
		for(int i = 0 ; i< end ; i++){
			cout<< vec[i] << " ";
		}
		cout<<endl;
		return;
	}
	Permutation(vec,start+1,end);
	for(int j  = start+1 ; j < end ; j++){
		rightRotate(vec,start,j);
		Permutation(vec,start+1,end);
		leftRotate(vec,start,j);
		
		
	}
}


int main() {
    vector<char> vec = {'E' , 'X' , 'A' , 'B'};
    sort(vec.begin() , vec.end());
    
    Permutation(vec,0,vec.size());

    return 0;
}

