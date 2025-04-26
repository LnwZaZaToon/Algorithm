#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
	
	int n;
	cin>>n;
 	priority_queue<int>st;
	for(int i = 0 ; i<n ;i++){
		char data;
		cin>>data;
		if(data == 'P'){
			int num;
			cin>>num;
			st.push(num);
		}
		else if(data == 'Q'){
			if(st.empty()){
				cout<<"-1"<<endl;
			}
			else{
				int temp = st.top();
				st.pop();
				cout<<temp<<endl;
			}
		}
	}
	
	
}
