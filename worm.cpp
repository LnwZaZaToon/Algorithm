#include<bits/stdc++.h>
using namespace std;
bool compare (const pair<int,int> &a , const pair<int,int> &b){
	double ratioA = (double)a.first/ a.second;
	double ratioB = (double)b.first/b.second;
	if(ratioA == ratioB) return a.second < b.second;
	return ratioA > ratioB;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n ;
	cin>> n;
	vector<pair<int,int>>vec(n);
	for(int i = 0 ; i< n ; i++){
		int  a , b;
		cin>> a >> b;
		vec[i] = {a,b};
	}
	int total = 0;
	int Maxcost = 0;
	double Ratio = 0.0;
	int bestDestroy = 0,  bestCost = 0;
	sort(vec.begin() , vec.end(), compare) ;
	for(int i = 0 ; i< n ; i++){
	//	cout<< vec[i].first<<" " << vec[i].second << endl;
		total += vec[i].first;
		Maxcost = max(Maxcost,vec[i].second);
		double currRatio = (double) total / Maxcost;
		if(Ratio < currRatio or (currRatio == Ratio && Maxcost < bestCost)) {
			Ratio = currRatio;
			bestCost = Maxcost;
			bestDestroy = total;
			
		}
	}	

	cout<< bestDestroy << " "<< bestCost;
	return 0 ;
}
