#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>> data(2*n-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k;
			cin >> k;
			data[i+j].push_back(k);
		}
	}
	for(int i=1;i<2*n-1;i++)
		sort(data[i].begin(),data[i].end());
	int s=0;
	priority_queue<int> q;
	for(int i=2*n-2;i>0;i--){
		for(int j=0;j<data[i].size();j++){
			q.push(data[i][j]);
		}
		//cout << q.top();
		s+=q.top();
		q.pop();
	}

	cout << s;
}

