#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Event{
public:
	int time;
	char type;
};

bool compare(const Event& a, const Event &b){
    if (a.time == b.time)
        return a.type == 'e'; 	
	return a.time < b.time;
}


void Check(vector<int>&vec1,vector<int>&vec2){
	vector<Event>event;
	for(int i= 0 ; i<vec1.size() ;i++){
		event.push_back({vec1[i],'e'});
		event.push_back({vec2[i],'x'});
		
	}
	sort(event.begin() , event.end(),compare);
		
	
	int Maxtime = 0;
	int start = 0 , end  = 0;
	int count = 0;
	
	for(const auto& ev :event){
		if(ev.type == 'e' ){
			count++;
			if(count > Maxtime){
				Maxtime = count;
				start = ev.time;
				
			}
		}
		else{
			if(count == Maxtime  ){
				end = ev.time;
			}
			count-- ;
		}
		
cout << start << " "  << end << " "<< count <<endl;
	}
	cout << start << " "  << end << " "<< Maxtime;
	
}



int main(){
	int n;
	cin>>n;
	vector<int>vec1(n);
	vector<int>vec2(n);
	for(int i = 0 ; i< n ;i++){
		cin>>vec1[i] >> vec2[i];
	}
	Check(vec1,vec2);
	
	
	return 0;
}
