#include <bits/stdc++.h>
using namespace std;

// Function to find XOR of all numbers from 1 to n
int xorUpto(int n)
{
    // XOR from 1 to n follows a repeating pattern
    // based on n % 4.

    // n % 4 == 0
    // Example:
    // 1 ^ 2 ^ 3 ^ 4 = 4
    if (n % 4 == 0)
        return n;

    // n % 4 == 1
    // Example:
    // 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1
    if (n % 4 == 1)
        return 1;

    // n % 4 == 2
    // Example:
    // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7
    if (n % 4 == 2)
        return n + 1;

    // n % 4 == 3
    // Example:
    // 1 ^ 2 ^ 3 = 0
    return 0;
}

// Function to find XOR from L to R
int findXOR(int L, int R)
{
    // XOR(L...R)
    // = XOR(1...R) ^ XOR(1...(L-1))
    return xorUpto(R) ^ xorUpto(L - 1);
}

int main()
{
    int L, R;

    cin >> L >> R;

    cout << findXOR(L, R);

    return 0;
}