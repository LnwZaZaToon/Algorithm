#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int len = 8;
vector<int>wire = {2,3,5};


void Backtrack(vector<int>&vec , int low, int high,int &count){
	if(low == high ){
		int sum = 0;
		int lens = 0;
		for(int i = 0 ; i< vec.size() ; i++){
			//cout<<vec[i];
			if(vec[i] == 1){
				sum+= wire[i];
				lens++;
			}
		}
		if(sum == len ){
			count = min(count,lens);
			/*for(int i = 1 ; i< vec.size() ; i++){
				cout<<vec[i];
			}
			cout<<endl;*/
		}
		//cout<<endl;		
		return;
	}
	vec[low+1] = 1;
	Backtrack(vec,low+1,high,count);
	vec[low+1] = 0;
	Backtrack(vec,low+1,high,count);
}




int main(){
	int n = 3;
	int count = INT_MAX;
	vector<int>vec (n,0);
	Backtrack(vec,-1,n,count);
	if(count == INT_MAX){
		cout<<"0";
	}
	else{
		cout<<count;
	}
	return 0;
}
