#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findMaxGuests(vector<int> arrl, vector<int> exit, int n)
{
   sort(arrl.begin(), arrl.end()); 
   sort(exit.begin(), exit.end()); 
   
   int guests_in = 0, max_guests = 0, start = 0, end = 0;
   int i = 0, j = 0;


   while (i < n && j < n) {
      if (arrl[i] <= exit[j]) {
          guests_in++;
          if (guests_in > max_guests) {
              max_guests = guests_in;
              start = arrl[i];    
          }
          i++;  
      } else {  
          if (guests_in == max_guests) {
              end = exit[j]; 
          }
          guests_in--;
          j++;
      }
   }

   cout << start << " " << end<<" "<<max_guests  << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);   
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    findMaxGuests(A, B, n);
    return 0;
}

