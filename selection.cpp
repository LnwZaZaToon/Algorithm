#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    int count = 0;
    
    for(int i = 0; i < n; i++){
        int index = i;
        for(int j = i + 1; j < n; j++){  // Start the inner loop from i+1
            if(vec[j] < vec[index]){   // Compare vec[j] with vec[index]
                index = j;
            }
        }
        swap(vec[i], vec[index]);
        if( i != index){
        	count++;
		}
    }
    
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout<<count;
    
    return 0;
}

