#include<bits/stdc++.h>
using namespace std;


int func(int &data){
	data + 3;
}




int MAXZ(vector<int>& vec , int n  ){
	if( n == 0 ) return vec[n];
	//return max(vec[n] ,MAXZ(vec,n-1));
	int t1 = vec[n] ;
	int t2 =  MAXZ(vec,n-1);
	if( t1 > t2){
		return t1;
	}
	else{
		return t2;
	}
}  


struct Student{
	char name[];
	int num;
};

int main(){
	vector<int>  vec = {2,1,2,4};
	
//cout << MAXZ(vec , vec.size()-1);
	int data = 5;
	cout << func(data);
	struct Student s1;
	struct Student *s2 = &s1;
	string s5 = "toon";
	cout << s5;
	s2->num = 1;
	cout << s2->num;
	
	char zaza []= "Tonnasdasd";
	string A = "C";
	char *ptr = &zaza[0];
	A += *&(ptr);
	cout << A;
	
//	cout << *ptr;
	

	
	return 0;
}
