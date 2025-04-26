#include<bits/stdc++.h>
using namespace std;

class Bags{
public:
	double price;
	double weight;
	double ratio;
};

bool compare (const Bags &a , const Bags &b){
	if(a.ratio == b.ratio){
		return a.weight < b.weight;
	}
	return a.ratio > b.ratio ;
}

int main(){
	int n , k ;
	cin>> n >> k ;
	vector<Bags>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>> vec[i].weight >> vec[i].price;
		vec[i].ratio = vec[i].price / vec[i].weight;
	}
	sort(vec.begin() , vec.end() , compare) ;
	for(int i = 0 ; i < n ; i++){
		cout << vec[i].price <<" " << vec[i].weight<<endl;
	}	
	
	int totalv = 0;
	int totalw = 0;
	for(int i = 0 ; i< n ; i++){
		if(totalw + vec[i].weight <= k ){
			totalv += vec[i].price;
			totalw += vec[i].weight;
		}
	}
	cout << totalv <<" "<< totalw ;
	return 0;
}
