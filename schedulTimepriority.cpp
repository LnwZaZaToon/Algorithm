#include<bits/stdc++.h>
using namespace std;

class Times{
public:
	int Shour;
	int Smin;
	int Ehour;
	int Emin;
};

bool compare(const Times &a , const Times &b){
	if(a.Shour == b.Shour) return a.Smin < b.Smin;
	return a.Shour < b.Shour;
}

int main(){
	int n ;
	cin>> n;
	vector<Times>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>>vec[i].Shour >> vec[i].Smin;
		cin>>vec[i].Ehour >> vec[i].Emin;
	}
	sort(vec.begin() , vec.end() , compare );
	for(int i = 0 ; i < n ; i++){
		cout<<vec[i].Shour<<":"<< vec[i].Smin<<" "<< vec[i].Ehour<<":"<< vec[i].Emin<<endl;
	}
	vector<pair<int,int>>cap;
	
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	
	for(auto data : vec){
		if(pq.empty()){
			pq.push({data.Ehour, data.Emin});
		}
		else{
			int hour = pq.top().first;
			int min = pq.top().second;
			if(hour < data.Shour || (hour == data.Shour && min < data.Smin ) ){
				pq.pop();
				pq.push({data.Ehour, data.Emin});
			}
			else{
				pq.push({data.Ehour, data.Emin});
			}
		}
		
		
	}
	cout<< pq.size();
	
	return 0;
}
/*
6
1 0 2 0
16 0 21 30
9 30 13 0
21 30 22 30
21 30 22 30
12 0 12 30
*/
