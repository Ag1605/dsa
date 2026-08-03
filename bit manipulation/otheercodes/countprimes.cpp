#include <bits/stdc++.h>
using namespace std;

// Function to count prime numbers less than n
int countPrimes(int n)
{
    // There are no prime numbers less than 2
    if (n <= 2)
        return 0;

    // Assume every number is prime initially
    vector<bool> isPrime(n, true);

    // 0 and 1 are not prime
    isPrime[0] = false;
    isPrime[1] = false;

    // Traverse from 2 to √n
    for (int i = 2; i * i < n; i++)
    {
        // If i is still marked as prime
        if (isPrime[i])
        {
            // Mark all multiples of i as not prime
            // Start from i*i because smaller multiples
            // have already been marked by smaller primes.
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Count all prime numbers
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
            count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << countPrimes(n);

    return 0;
}