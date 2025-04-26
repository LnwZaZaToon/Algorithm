#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
bool isPrime(int n) {
    if (n <= 1)
        return false; 

    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0)
            return false; 
    }

    return true; 
}

vector<int> primeRange(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        if (isPrime(i))
            ans.push_back(i);
    }
    sort(ans.begin(),ans.end(),greater<int>());
  /*  for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " "; 
    cout << endl;*/
    return ans; 
}


void shellSort(int arr[], int n)
{
    vector<int> gaps = primeRange(n);
    gaps.push_back(1);
    
    for (int gap : gaps)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        printArray(arr, n);
    }
}

int main()
{
 /*   int arr[] = {16, 25, 2, 54, 36, 9, 12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);*/
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i< n ;i++){
    	cin>>arr[i];
	}
    shellSort(arr, n);

    return 0;
}

