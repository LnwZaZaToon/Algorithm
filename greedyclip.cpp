#include<bits/stdc++.h>
using namespace std;


class Times {
public:
	int start;
	int end;
	int duration;
};


int compare(const Times &a , const Times &b){
	if(a.duration == b.duration ) return a.start < b.start;
	return a.duration > b.duration;
}


int main(){
	int n , k ;
	cin >> n >> k ;
	vector<Times> vec(n);
	for(int i = 0 ; i <n ; i++){
		cin >> vec[i].start >> vec[i].end;
		vec[i].duration = vec[i].end - vec[i].start;
	}
	sort(vec.begin()  , vec.end() , compare);
	cout<<"-------------------------"<<endl;
	for(int i = 0 ; i <n ; i++){
		cout << vec[i].start << " "<< vec[i].end << endl;
	}
	
	return 0;
}
