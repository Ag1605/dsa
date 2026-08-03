#include <bits/stdc++.h>
using namespace std;

// Function to divide two numbers without using
// multiplication (*), division (/), or modulus (%)
int divide(int dividend, int divisor)
{
    // Special case:
    // INT_MIN = -2147483648
    // If we divide INT_MIN by -1, the answer becomes 2147483648,
    // which is greater than INT_MAX (2147483647).
    // So return INT_MAX to avoid overflow.
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine whether the final answer should be negative.
    // XOR (^) returns true only if exactly one number is negative.
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Convert both numbers to positive.
    // We use long long because abs(INT_MIN) cannot be stored in int.
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);

    // Stores the final quotient
    long long quotient = 0;

    // Continue until dividend becomes smaller than divisor
    while (a >= b)
    {
        // temp stores the current multiple of divisor
        long long temp = b;

        // multiple stores how many times divisor has been doubled
        long long multiple = 1;

        // Keep doubling temp until the next double becomes larger than a
        while ((temp << 1) <= a)
        {
            // Double temp
            temp <<= 1;

            // Double multiple
            multiple <<= 1;
        }

        // Remove the largest possible multiple of divisor
        a -= temp;

        // Add that multiple to the answer
        quotient += multiple;
    }

    // If the answer should be negative, apply the sign
    if (negative)
        quotient = -quotient;

    return (int)quotient;
}

int main()
{
    int dividend, divisor;

    cin >> dividend >> divisor;

    cout << divide(dividend, divisor);

    return 0;
}