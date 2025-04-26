#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class MaiProm{
public:
	string color;
	int datex;
	int number;
};

bool Compare(const MaiProm a , const MaiProm b ){
	return a.datex<b.datex;
}

int Check(vector<MaiProm>&a , vector<MaiProm> &b){
	int count = 0;
	for(int i = 0 ; i< a.size() ; i++){
		if(a[i].number == b[i].number){
			count ++;
		}
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	vector<MaiProm>v1(n);
	for(int i = 0 ; i< n ;i++){
		cin>> v1[i].color >> v1[i].datex >> v1[i].number;
	}
	vector<MaiProm>v2 = v1;
	
	sort(v2.begin(),v2.end() , Compare);
	
/*	for(int i = 0 ; i<v2.size() ;i++){
		cout<< v2[i].color<< endl;
	}*/
	cout<< Check(v1,v2);
	
	return 0;
}
