#include<bits/stdc++.h>
using namespace std;

class Times{
public:
	double start;
	double end;
	double duration ;
};

bool compare(const Times &a ,  const Times &b){
	if(a.duration == b.duration){
		return a.start > b.start;
	}
	return a.duration > b.duration;
}


int main(){
	int n ;
	cin>>n;
	vector<Times>vec(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i].start >> vec[i].end;
		double du = vec[i].end - vec[i].start;
		vec[i].duration = du;
	}
	sort(vec.begin(),vec.end(),compare);
/*	for(int i = 0 ; i< n ;i++){
		cout<<vec[i].start << " "<< vec[i].end<< endl;
	}*/
	vector<int> endTimes(n,0);
	int count = 0;
	for(int i = 0 ; i< vec.size() ; i++){
		int j = 0;
		for( j ; j < vec.size() ; j++){
			if(endTimes[j] <= vec[i].start){
				endTimes[j] = vec[i].end;				
				break;
			}
			cout<<j<<" ";
			count = max(count,j);
		} 
	}
	cout<<count+1;
	
}
