#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfDigits(int n)
    {

        // Base case
        // If number becomes 0, return 0
        if (n == 0)
            return 0;

        // Recursive case
        // Last digit + sum of remaining digits
        return (n % 10) + sumOfDigits(n / 10);
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    cout << obj.sumOfDigits(n);

    return 0;
}