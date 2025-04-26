#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

long long karatsuba(long long a, long long b)
{
    if (a < 10 || b < 10)
        return a * b;
    int n = max(to_string(a).length(), to_string(b).length());
    int n2 = n / 2;
    long long power_of_10 = 1;
    for (int i = 0; i < n2; ++i) {
        power_of_10 *= 10;
    }
    long long x = a / power_of_10;
    long long y = a % power_of_10;
    long long z = b / power_of_10;
    long long w = b % power_of_10;

    long long p = karatsuba(x, z);
    long long q = karatsuba(x + y, z + w);
    long long r = karatsuba(y, w);

    return power_of_10 * power_of_10 * p + power_of_10 * (q - p - r) + r;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << karatsuba(a, b) << endl;
    return 0;
}

