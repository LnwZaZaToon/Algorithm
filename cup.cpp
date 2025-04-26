#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void sortSearchReduce(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int>newvec;
    for(int i = 0 ; i< arr.size() ; i++){
    	vector<int>temp;
    	while(arr[i] != 0){
    		int a = arr[i]%10;
    		temp.push_back(a);
    		arr[i] = arr[i]/10;
		}
		for(int j = temp.size()-1 ; j>=0 ;j-- ){
			newvec.push_back(temp[j]);
		}
	}
    vector<int> reduced;
    vector<int> digit;
    for (size_t i = 0; i < newvec.size(); ++i) {
        if (i == 0 || newvec[i] != newvec[i - 1]) {
            reduced.push_back(newvec[i]);
        }
        else{
        	digit.push_back(newvec[i]);
		}
    }
	
	for(int i = 0 ; i<newvec.size() ; i++){
		cout<<newvec[i];
	}
	cout<<endl;
	for(int i = 1 ; i<digit.size() ; i++){
		if(digit[i] == digit[i-1]) 
		cout<<digit[i]<<" "; 
	}	
	cout<<endl;
	for(int i = 0 ; i< reduced.size() ; i++){
		cout<< reduced[i];
	}
}

int main() {
  //	vector<int>vec = {23, 22 ,18, 11 ,13  };
  int n;
  cin>>n;
  vector<int>vec(n);
  for(int i = 0 ; i< n ; i++){
  	cin>>vec[i];
  }
  	sortSearchReduce(vec);
    return 0;
}

