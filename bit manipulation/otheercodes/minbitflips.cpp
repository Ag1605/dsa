#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of bit flips
// required to convert 'start' into 'goal'
int minBitFlips(int start, int goal)
{
    // XOR gives the positions where the bits are different.
    // Same bits  -> 0
    // Different bits -> 1
    int x = start ^ goal;

    // Stores the number of different bits
    int count = 0;

    // Traverse all bits of x
    while (x)
    {
        // Check whether the last bit is 1.
        // If yes, increment the count.
        count += (x & 1);

        // Right shift x by one position
        // to check the next bit.
        x >>= 1;
        /* */
    }

    // Return the total number of bit flips
    return count;
}

int main()
{
    /*another approch class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int x = start ^ goal;
        int count = 0;

        while (x)
        {
            x = x & (x - 1);
            count++;
        }

        return count;
    }
};*/
    int start, goal;

    cin >> start >> goal;

    cout << minBitFlips(start, goal);

    return 0;
}