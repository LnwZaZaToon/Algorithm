#include<bits/stdc++.h>
using namespace std;


class Time{
	
public:
	int  start;
	int  end;
	int  duration;
};



bool compare(const Time &a , const Time &b){
	return a.duration > b.duration;
}

int main(){
	int n , k;
	cin>>n>>k;
	vector<Time>vec(n);
	for(int i = 0 ; i <n ; i++){
		int s , e;
		cin>>s >>e;
		vec[i].start = s;
		vec[i].end = e;
		vec[i].duration = e-s;
	}
	cout<<"---------------------"<<endl;
	sort(vec.begin() , vec.end() , compare);
	for(int i = 0 ; i <n ; i++){
		cout<<vec[i].start<<" "<<vec[i].end<<endl;
	}	
	
	return 0;
}
