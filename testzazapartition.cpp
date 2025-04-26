#include<iostream>
#include<vector>
using namespace std;

int median(vector<int>&vec , int low ,int high){
	int mid = (low+high)/2;
	if(vec[low] > vec[mid]){
		swap(vec[low],vec[mid]);
	}
	if(vec[low] > vec[high]){
		swap(vec[high],vec[low]);
	}
	if(vec[mid]>vec[high]){
		swap(vec[mid],vec[high]);
	}
	swap(vec[mid] , vec[high]);
	return high;
}



int partition(vector<int>& a, int l, int r) {

    int pi = median(a, l, r);
    int p = a[pi];
    cout<<p<<" ";
    
    swap(a[l], a[pi]);

    int i = l, j = r + 1;
    
    while(1) {
        do { ++i; 
		} while (a[i] <= p && i <= r);
        do { --j; 
		} while (a[j] > p && j >= l);
		
        if (i >= j) {
			break;
		}	
        swap(a[i], a[j]);
    }

    swap(a[l], a[j]);

    return j;
}

void quickSort(vector<int>& s, int l, int r) {
    if (l < r) {
        int p = partition(s, l, r);
        quickSort(s, l, p - 1);
        quickSort(s, p + 1, r);
    }
}



int main(){
	
	vector<int>vec = {16 ,25 ,2 ,54, 36, 9, 12 ,66};
	quickSort(vec,0,vec.size()-1);
/*	for(int i = 0 ; i < vec.size() ;i++){
		cout<<vec[i] << " ";
	}*/
	
	
	return 0;
}
