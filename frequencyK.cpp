#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int Freq(vector<int>&vec , int k){
	unordered_map<int,int>count;
	priority_queue<pair<int,int>> pq;
	for(auto it : vec){
		count[it]++;
	}
	for(auto it : count){
		cout<<it.second<<" |" << it.first <<"\n";
		pq.push({it.second,it.first});
	}
	vector<int> ans;
	while(k--){
		ans.push_back(pq.top().second);
		pq.pop();
	}
	cout<<endl;
	for(auto it : ans){
		cout<<it <<" ";
	}
	
}




int main(){
	vector<int>vec = {1,1,1,1,2,2,3};
	Freq(vec,2);
	
	return 0;
}
