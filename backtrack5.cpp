#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int len ;
int n = 3;
vector<int>wire (n+1,-1);


void Backtrack(vector<int>&vec , int low, int high,int &count){
	if(low == high ){
		int sum = 0;
		int lens = 0;
		for(int i = 1 ; i< vec.size() ; i++){
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
	int count = INT_MAX;
	cin>>len;
	for(int i = 1 ; i<= n ; i++){
		cin>>wire[i];
	}
	vector<int>vec (n+1,0);
	Backtrack(vec,0,n,count);
	if(count == INT_MAX){
		cout<<"0";
	}
	else{
		cout<<count;
	}
	return 0;
}
