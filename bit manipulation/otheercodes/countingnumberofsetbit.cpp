#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int count = 0;

    // Traverse all bits
    while (n > 0)
    {

        // Check if the last bit is set
        if (n & 1)
            count++;

        // Remove the last bit
        n = n >> 1;
    }

    cout << count;

    return 0;
}