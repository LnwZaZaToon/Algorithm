#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Points{
public:
	long long int x;
	long long int y;
};

bool compare(const Points a , const Points b){
    if(a.x!=b.x){	
		return a.x>b.x;
	}
    return a.y<b.y;
}


int main(){
	long long int n;
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n;
	vector<Points>vec(n);
	for(long long int i = 0 ; i< n ;i++){
		cin>>vec[i].x >>vec[i].y;
	}
	sort(vec.begin() , vec.end() , compare );
	cout<<"----------------"<<endl;
	
	for(int i = 0 ; i< n ;i++){
		cout<<vec[i].x <<" "<< vec[i].y<<endl;
	}	
	vector<Points>vec2;
	long long int mx=0;	
    for(int i=0;i<vec.size();i++){
        if(vec[i].y>=mx){
            vec2.push_back(vec[i]);
            mx=vec[i].y;
        }
    }
    
    reverse(vec2.begin(),vec2.end());
    cout<<"----------------"<<endl;
	
/*	vector<Points>vec2;
	for(long long int i = 0 ; i<n ;i++){
		int flag = 0;
		for(long long int j=i+1 ; j<n ;j++){
			if(vec[i].x < vec[j].x && 
			vec[i].y < vec[j].y ){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			vec2.push_back(vec[i]);
		}
	}*/
	
	for(int i = 0 ; i< vec2.size() ;i++){
		cout<<vec2[i].x <<" "<< vec2[i].y<<endl;
	}
	return 0;
}

/*
7
1 2
2 4
4 1
7 3
5 5
6 6
3 7

*/
