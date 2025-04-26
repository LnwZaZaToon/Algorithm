#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function to multiply two large integers using Karatsuba's algorithm
long long karatsuba(long long x, long long y) {
    // Base case: if the number is small enough (less than 10), multiply directly
    if (x < 10 || y < 10) {
        return x * y;
    }
    
    // Find the size of the numbers (number of digits)
    int n = max(to_string(x).length(), to_string(y).length());
    int half = n / 2;

    // Split the numbers into two halves
    long long highX = x / pow(10, half);
    long long lowX = x % (long long)pow(10, half);
    long long highY = y / pow(10, half);
    long long lowY = y % (long long)pow(10, half);

    // Recursively compute three products
    long long z0 = karatsuba(lowX, lowY);  // Low part * Low part
    long long z1 = karatsuba(lowX + highX, lowY + highY);  // (Low part + High part) * (Low part + High part)
    long long z2 = karatsuba(highX, highY);  // High part * High part

    // Combine the results according to the Karatsuba formula
    long long result = z2 * pow(10, 2 * half) + (z1 - z2 - z0) * pow(10, half) + z0;
    return result;
}

int main() {
    long long a = 1234567890123456789;  // First large number
    long long b = 9876543210987654321;  // Second large number

    long long result = karatsuba(a, b);
    cout << "Result: " << result << endl;

    return 0;
}

