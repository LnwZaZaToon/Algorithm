#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	vector<int> vec = {1,5, 10, 4 ,8 ,2, 6 };
	priority_queue<int> p;
	int k = 3;
	int realk = k;
	for(int i = 0 ; i< vec.size() ; i++){
		p.push(vec[i]);
	}
	int sum = 0;
	while(k--){
		int top = p.top();
		sum += top;
		p.pop();
	}
	cout<<sum/realk;
	
	return 0;
}
