#include<iostream>
#include<vector>
using namespace std;
int n = 4;
vector<int>weight (n+1,-1);
vector<int>item (n+1,-1);
vector<int>vec = { -1,0,0,0,0};

//12,5,4,2
//-1,8,7,4,2

int FindSubset(vector<int>&vec,int low , int high,int k,int &maxitem){
	if(low == high ){
	/*	for(int i = 1 ; i< vec.size() ;i++){
			cout<<vec[i] <<" ";
		}
		cout<<endl;*/
		int w = 0 ;
		for(int i = 1 ; i< vec.size() ; i++){
			if(vec[i] == 1){
				w += weight[i];
			}
		};
		int itm = 0;
		if(w <= k){
			for(int i = 1 ; i < vec.size() ;i++){
				if(vec[i] == 1){
					 itm += item[i];
				}
			}
			maxitem = max(maxitem , itm);
		}
	}else{
		vec[low+1] = 1;
		FindSubset(vec,low+1,high,k,maxitem);
		vec[low+1] = 0;
		FindSubset(vec,low+1,high,k,maxitem);	
	}
	
}






int main(){
	int k ;
	cin>>k;
	for(int i = 1 ; i<= n ; i++){
		cin>>item[i];
	}
	for(int i = 1 ; i<= n ; i++){
		cin>>weight[i];
	}
	int maxitem = 0;
	FindSubset(vec,0,n,k,maxitem);
	cout<<maxitem;
	
	return 0;
}

