#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Runner{
public:
	int ID;
	int hour;
	int min;
	bool frd = false;
};

bool compare(const Runner &a , const Runner &b){
	if(a.hour == b.hour){
		return a.min < b.min;
	}
	return a.hour< b.hour;
}


int main(){
	int n;
	cin>>n;
	vector<int> bro(n);
	for(int i = 0 ; i< n;i++){
		cin>>bro[i];
	}
	int num2;
	cin>>num2;
	vector<Runner>vec(num2);
	for(int i = 0 ; i< num2 ;i++){
		cin>>vec[i].ID>> vec[i].hour >> vec[i].min;
	}
	sort(vec.begin() , vec.end() , compare);
	for(int i = 0 ; i< num2 ;i++){
		for(int j = 0 ; j< n ;j++){
			if(vec[i].ID == bro[j]){
				vec[i].frd = true;
			}
		}
	}
	cout<<"-----------------------------"<<endl;
	int count = 0;
	int flag = true;
	vector<Runner>ans;
	for(int i = 0 ; i< num2 ;i++){
		if(vec[i].frd &&vec[i].hour != -1 &&vec[i].hour < 6  || 
		vec[i].hour == 6 && vec[i].min == 0){
			ans.push_back(vec[i]);
			count ++;
		}
	}	
	
	cout<<ans[0].ID<<" "<<count;
	
	return 0;
}


/* Testcase 



4
123 456 999 73
6
111 5 3
456 -1 -1
123 4 59
73 6 0
520 -1 -1
999 6 0








5
3 5 2 7 1
10
5 8 3
4 6 20
9 4 10
10 5 20
1 6 1
2 4 20
3 4 20
6 4 20
7 4 15
8 4 10


*/
