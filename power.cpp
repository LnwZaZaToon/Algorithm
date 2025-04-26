#include <iostream>
using namespace std;





int power(int a, int n,int &count) {
    if (n == 0) {
        return 1; 
    }
    
    if (n == 1) {
        return a; 
    }

 
    int half_power = power(a, n / 2,count);
    int result = half_power * half_power;
    count++;

    if (n % 2 != 0) {
        result *= a; 
        count++;
    }

    return result;
}

int main() {
    int a, n;
    cin >> a >> n; 
    int count = 0;
    int result = power(a, n,count);
    cout << result << " " << count << endl;

    return 0;
}

