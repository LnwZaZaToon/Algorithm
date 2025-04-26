#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


class Process{
public:
	int ID;
	int arrival;
	int service;
};


bool compare(const Process& a , const Process& b){
	return a.arrival < b.arrival;
}


void Check(vector<Process>&vec,int n){
	stack<Process>st;
	sort(vec.begin() , vec.end() , compare);
	st.push(vec[0]);
	int round = 0,j=0;
	while(!st.empty()){
		Process temp = st.top();
		st.pop();
		int tempServiceTime = temp.service;
        for(int i = 0 ; i < temp.service ; i++){
            cout << temp.ID << " : " << tempServiceTime << endl;
            tempServiceTime--;
            round++;
            if(round == vec[j].arrival){
                st.push(vec[j]);
                j++;
            }
        }
	}
}


int main(){
	int n;
	cin>>n;
	vector<Process>vec(n);
	for(int i= 0 ; i<n ;i++ ){
		cin>>vec[i].ID >> vec[i].arrival>> vec[i].service;
	}
	
	Check(vec,n);
	
	
	
	return 0;
}
