#include<bits/stdc++.h>
using namespace std;

class Times {
public:
	int start;
	int end;
	int duration;
};

bool compare( const Times &a , const Times &b){
	if(a.duration == b.duration) return a.start > b.start; 
	return a.duration > b.duration;
}

int main(){
	int n , k;
	cin >> n >> k;
	vector<Times>vec(n);
	for(int i = 0 ; i < n ; i++){
		int start , end;
		cin >> start >> end;
		vec[i].start = start;
		vec[i].end = end;
		vec[i].duration = end - start;
	}
	for(int i = 0 ; i < n ; i++){
		cout << vec[i].start <<" " << vec[i].end <<endl;
	}
	
	sort(vec.begin() , vec.end()  , compare);
	int count = 0;
	vector<int>room(k,0);
	for(auto data : vec){
		for(int i = 0 ; i < k ; i++){
			if(room[i] <= data.start ){
				room[i] = data.end;
				count ++;
				break;
			}
		}
	}
	cout << count;
	
	
	return 0;
}
