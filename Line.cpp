#include<bits/stdc++.h>
using namespace std;

class Lines{
public:
	int start;
	int end;
};

bool compare(const Lines &a , const Lines &b){
	if(a.start == b.start){
		return a.end < b.end;
	}
	
	return a.start < b.start;
}

int main(){
	int n ;
	cin >> n;
	vector<Lines>vec(n);
	for(int i = 0 ; i < n ; i++){
		cin>> vec[i].start >> vec[i].end;
	}
	sort(vec.begin() , vec.end() ,compare);
	int xa , xb;
	cin>>xa >> xb;
	
	for(int i = 0 ; i < n ; i++){
		//cout<< vec[i].start <<" "<< vec[i].end << endl;
	}
	
	int Realstart =xa, Realend = xa;
	
	int i = 0;
	while( i < n && Realend < xb){
		int bestend = Realend;
		int beststart = Realend;
		while(i < n && vec[i].start <= Realend){
			if(vec[i].end > bestend){
				bestend = vec[i].end;
				beststart = vec[i].start;
				
			}
			i++;
		}
		cout<< beststart <<" "<< bestend <<endl;
		Realend = bestend;
		
	}
	
	
	
	return 0;
}
