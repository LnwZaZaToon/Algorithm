#include<bits/stdc++.h>
using namespace std;

class Bags{
public:
	int weight ;
	int price;
};
bool compare( const Bags &a , const Bags &b){
	if(a.price == b.price){
		return a.weight< b.weight;
	}
	return a.price > b.price;
}
int main(){
	int n , w;
	cin>> n >> w;
	vector<Bags>vec(n);
	for(int i = 0 ; i < n;  i++){
		cin>>vec[i].weight;
	}
	for(int i = 0 ; i < n;  i++){
		cin>>vec[i].price;
	}
	sort(vec.begin() , vec.end() , compare);
	
	int totalWeight=  0;
	int totalPrice = 0;
	for(int i = 0 ; i<n ; i++){
		cout<<vec[i].price <<" "<< vec[i].weight<<endl;
	}
	
	for(int i = 0 ; i < n;  i++){
		if(totalWeight + vec[i].weight <= w){
			totalPrice += vec[i].price;
			totalWeight += vec[i].weight;
		}
	}
	cout<< totalWeight <<" "<<totalPrice<<" "<<w-totalWeight;
	
	
	return 0;
}
