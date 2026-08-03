#include <bits/stdc++.h>
using namespace std;

// Function to convert Binary to Decimal
int binaryToDecimal(string str)
{

    // Length of binary string
    int len = str.length();

    // 'val' stores the current power of 2.
    // Initially it is 2^0 = 1 (rightmost bit).
    int val = 1;

    // Variable to store the final decimal number
    int num = 0;

    // Traverse the binary string from right to left
    // because the rightmost bit has the smallest power (2^0)
    for (int i = len - 1; i >= 0; i--)
    {

        // If the current bit is '1',
        // add its corresponding power of 2 to the answer.
        if (str[i] == '1')
        {
            num = num + val;
        }

        // Move to the next higher power of 2
        // 1 → 2 → 4 → 8 → 16 ...
        val = val * 2;
    }

    // Return the decimal value
    return num;
}

int main()
{

    // Input binary number as a string
    string str;
    cin >> str;

    // Print the decimal equivalent
    cout << binaryToDecimal(str);

    return 0;
}