#include<iostream>
#include<vector>
#include<climits>
using namespace std;



class Times{
public:
	int start;
	int end;
};

int main(){
	int n;
	cin>>n;
	vector<Times>vec(n);
	int maxZ = vec[0].start;
	for(int i = 0 ; i< n ;i++){
		cin>>vec[i].start;
		cin>>vec[i].end;
		maxZ = max(vec[i].start , vec[i].end);
	}
	vector<int>vec2(maxZ+1,0);
	for(int i = 0 ; i< n ;i++){
		for(int j=vec[i].start ; j<=vec[i].end ; j++){
			vec2[j]++;
		}
	}
	for(int i = 0 ; i< vec2.size() ;i++){
		cout<<vec2[i] <<" ";
	}
	cout<<endl;
	int count = 0;
	int start , end;
	bool flag = false;
	for(int i = 1 ; i<vec2.size() ;i++){
		if(vec2[i]>count){
			count = vec2[i];
			start = i;
			end = i;	
			flag = true;		
		}
		else if(vec2[i] == count && flag){
			end = i;
		}
		else if(vec2[i] < count ){
			flag = false;
		}
		cout<<start<<" "<<end << " "<< count <<endl;
	}
	
	
	return 0;
}
