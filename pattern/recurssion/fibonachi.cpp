#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {

        // Base case
        if (n == 0)
        {
            return 0;
        }

        // Base case
        if (n == 1)
        {
            return 1;
        }

        // Recursive case
        // nth Fibonacci = (n-1)th Fibonacci + (n-2)th Fibonacci
        return fib(n - 1) + fib(n - 2);
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    cout << obj.fib(n);

    return 0;
}