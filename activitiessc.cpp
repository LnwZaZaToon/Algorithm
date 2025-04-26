#include<bits/stdc++.h>
using namespace std;

class Times{
public:
	int start ;
	int end;
	int duration;
};

bool compare(const Times &a , const Times &b){
	if(a.duration == b.duration ){
		return a.start < b.start;
	}
	return a.duration > b.duration;
}

bool compare2(const Times &a , const Times &b){
	if(a.start == b.start ){
		return a.end < b.end;
	}
	return a.start > b.start;
}


int main(){
	int n , k;
	cin>> n >> k;
	vector<Times> vec(n);
	for(int i = 0 ; i< n; i++){
		cin>>vec[i].start >> vec[i].end;
		vec[i].duration = vec[i].end - vec[i].start;
	}
	
	sort(vec.begin() , vec.end() , compare2);
	for(int i = 0 ; i< n; i++){
		cout<< vec[i].start  <<" "<< vec[i].end<<endl;
	}
	
	vector<int>BestEnd(k,0);
 	priority_queue<int, vector<int>, greater<int>> pq(k,0);
	int count = 0;
	
	for(int i = 0 ; i< n ; i++){
		/* for(int j = 0 ; j< k ;j++){
		 	if(BestEnd[j] <= vec[i].start){
		 		BestEnd[j] = vec[i].end;
		 		count++;
		 		break;
			 }
		 }*/
		if( pq.top() <= vec[i].start){
			pq.pop();
		}
		if(pq.size() < k ){		
            pq.push(vec[i].end); // Assign a resource
            count++;
		}

		
	}
	cout<<count;
	
	
	
	
	return 0;
}
