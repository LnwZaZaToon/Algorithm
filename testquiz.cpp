#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
	vector<int >vec = {12,34,56,78,90,111};
	vector<int>newvec(vec.size());
	for(int i = 0 ; i< vec.size() ; i++){
		priority_queue<int> pp ;
		int count = 0;
		while(vec[i] != 0){
			++count;
			int a = vec[i] % 10;
			pp.push(a);
			vec[i] = vec[i] / 10;	
		}
		while(!pp.empty() && count >= 0){
			int top = pp.top();
			pp.pop();
			vec[i] += top*pow(10,count-1);
			count--;
		}
	}
	
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i = 0 ; i< vec.size() ; i++){
		cout<< vec[i] << " ";
	}
	
	
	return 0;
}
