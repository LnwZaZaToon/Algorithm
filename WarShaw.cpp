#include<bits/stdc++.h>
using namespace std;


int main(){
	vector<vector<int>> vec( 101 , vector<int>(101,INT_MAX) );
	int MaxNode = -1 , MaxEdge = -1;
	while(true){
		int node , edge;
		cin>> node >> edge;
		if(node == 0 && edge == 0) break;
		vec[node][edge] = 1;
		MaxNode = max(MaxNode , max(node,edge));
	//	MaxNode = max(MaxNode, max(node, edge));
	}
	
	for(int i = 1 ; i <= MaxNode ; i++){
		vec[i][i] = 0;
	}


    for(int k = 1 ; k <= MaxNode ; k++ ){
    	for(int i = 1 ; i <= MaxNode ; i++){
    		for(int j = 1 ; j <= MaxNode ; j++){
    			if(vec[i][k] != INT_MAX && vec[k][j]!= INT_MAX) 
    				vec[i][j] = min(vec[i][j] , (vec[i][k] + vec[k][j]) );
				
			}
		}
	}
/*	for (int i = 1; i <= MaxNode; i++) {
        for (int j = 1; j <= MaxNode; j++) {
             cout<<vec[i][j]<<" ";
        }
        cout << endl;
    }*/
	double total = 0;
	double count = 0;
	for (int i = 1; i <= MaxNode; i++) {
        for (int j = 1; j <= MaxNode; j++) {
            if(vec[i][j] != INT_MAX && i != j){
            	total +=vec[i][j];
             	count++;	
			}	 
        }
    
    }
    cout<<fixed << setprecision(3)<<total / count;
   
	return 0;
}
