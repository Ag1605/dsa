
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Modulo value to prevent integer overflow.
    long long MOD = 1e9 + 7;


    // Function to calculate (a^b) % MOD
    // using Binary Exponentiation.
    long long power(long long a, long long b)
    {
        // BASE CASE:
        // Any number raised to power 0 is 1.
        if (b == 0)
        {
            return 1;
        }

        // STEP 1:
        // Calculate a^(b/2) recursively.
        long long half = power(a, b / 2);

        // STEP 2:
        // Square the half result.
        // This calculates a^(b) when b is even.
        long long result = (half * half) % MOD;

        // STEP 3:
        // If exponent is odd, multiply by a once more.
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }

        // Return the final power.
        return result;
    }


    // Function to count good numbers of length n.
    int countGoodNumbers(long long n)
    {
        // Number of even positions:
        // Index 0, 2, 4, ...
        long long even = (n + 1) / 2;

        // Number of odd positions:
        // Index 1, 3, 5, ...
        long long odd = n / 2;

        // Every even position has 5 choices.
        long long evenWays = power(5, even);

        // Every odd position has 4 choices.
        long long oddWays = power(4, odd);

        // Multiply both possibilities.
        // Take modulo to keep the answer within limits.
        long long ans = (evenWays * oddWays) % MOD;

        return ans;
    }
};


int main()
{
    Solution obj;

    // Length of the digit string.
    long long n = 5;

    // Calculate total good numbers.
    int ans = obj.countGoodNumbers(n);

    cout << "Number of Good Numbers: " << ans << endl;

    return 0;
}
