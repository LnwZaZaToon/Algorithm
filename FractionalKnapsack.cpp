#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a , const pair<int,int> &b){
	
	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;
	return r1>r2;
	
}

int main(){
	int n ,weight;
	cin>>n >> weight;
	vector<pair<int,int>>vec(n);
	for(int i = 0 ; i<n ; i++){
		cin>>vec[i].second;
	}
	for(int i = 0 ; i<n ; i++){
		cin>>vec[i].first;
	}
	sort(vec.begin() , vec.end() , compare);
/*	for(int i = 0 ; i< n ;i++){
		cout<< vec[i].first << endl;
	}*/
	
	double total = 0;
	double currweight = 0;
	for(int i = 0 ; i< n ; i++){
		if(currweight + vec[i].second <= weight){
			total += vec[i].first;
			currweight += vec[i].second;
		}
		else{
			double rest = weight - currweight ;
			total += vec[i].first * ((double)rest/vec[i].second); 
			cout<< fixed << setprecision(2)<< (rest / vec[i].second) ;
			break;
		}
	}
	cout<<fixed<<setprecision(2)<< total  ;
	
	
	return 0;
}
