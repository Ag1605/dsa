#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------------------------------------------------
    // Function: isPrime()
    // Purpose : Check whether a number is prime or not
    // ---------------------------------------------------------
    bool isPrime(int n) {

        // Numbers less than 2 are NOT prime.
        // Example: 0 and 1 are not prime.
        if (n < 2)
            return false;

        // We only need to check divisors up to sqrt(n).
        //
        // Why?
        // If n has a factor greater than sqrt(n),
        // then its other factor must be smaller than sqrt(n).
        //
        // Example:
        // 36 = 6 × 6
        // 36 = 4 × 9
        //
        // So checking up to sqrt(n) is enough.
        for (int i = 2; i * i <= n; i++) {

            // If n is completely divisible by i,
            // then n has a factor other than 1 and itself.
            // Therefore, n is NOT prime.
            if (n % i == 0)
                return false;
        }

        // No divisor was found.
        // Therefore, n is prime.
        return true;
    }


    // ---------------------------------------------------------
    // Function: makePalindrome()
    // Purpose : Create an odd-length palindrome
    //
    // Example:
    // x = 123
    //
    // Result = 12321
    // ---------------------------------------------------------
    int makePalindrome(int x) {

        // Initially, result contains the original number.
        //
        // Example:
        // x = 123
        // result = 123
        int result = x;


        // Remove the last digit from x.
        //
        // We remove the last digit because it is the
        // middle digit of the palindrome and should NOT
        // be repeated.
        //
        // Example:
        // 123 / 10 = 12
        //
        // We will reverse 12 and attach it to 123.
        x /= 10;


        // Continue until there are no digits left.
        while (x > 0) {

            // Get the last digit of x.
            //
            // Example:
            // x = 12
            // x % 10 = 2
            //
            // Then:
            // result = 123 * 10 + 2
            //        = 1232
            result = result * 10 + x % 10;


            // Remove the last digit from x.
            //
            // Example:
            // 12 / 10 = 1
            // 1 / 10  = 0
            x /= 10;
        }


        // Return the palindrome.
        //
        // Example:
        // 123 → 12321
        return result;
    }


    // ---------------------------------------------------------
    // Function: primePalindrome()
    // Purpose :
    // Find the smallest number >= n which is BOTH:
    //
    // 1. A palindrome
    // 2. A prime number
    // ---------------------------------------------------------
    int primePalindrome(int n) {

        // -----------------------------------------------------
        // Special cases
        // -----------------------------------------------------
        //
        // These are the single-digit prime palindromes:
        //
        // 2, 3, 5, 7
        //
        // 11 is also a prime palindrome.
        //
        // We handle them directly.
        // -----------------------------------------------------

        if (n <= 2)
            return 2;

        if (n <= 3)
            return 3;

        if (n <= 5)
            return 5;

        if (n <= 7)
            return 7;

        // 11 is the ONLY even-length prime palindrome.
        if (n <= 11)
            return 11;


        // -----------------------------------------------------
        // Generate possible palindromes.
        //
        // Instead of checking:
        //
        // n, n+1, n+2, n+3, ...
        //
        // we directly CREATE palindrome numbers.
        //
        // This makes the solution much faster.
        // -----------------------------------------------------

        for (int x = 1; ; x++) {

            // Create an odd-length palindrome from x.
            //
            // Examples:
            //
            // x = 1   → 1
            // x = 2   → 2
            // x = 10  → 101
            // x = 11  → 111
            // x = 12  → 121
            // x = 123 → 12321
            int palindrome = makePalindrome(x);


            // We need the palindrome to be greater than
            // or equal to the given n.
            //
            // Example:
            // n = 13
            //
            // palindrome = 1
            // 1 >= 13 → false
            //
            // palindrome = 101
            // 101 >= 13 → true
            //
            // But it also needs to be PRIME.
            if (palindrome >= n && isPrime(palindrome)) {

                // We found the smallest prime palindrome.
                return palindrome;
            }
        }
    }
};


// -------------------------------------------------------------
// MAIN FUNCTION
// Used to test the solution locally.
// -------------------------------------------------------------
int main() {

    // Create an object of Solution class.
    Solution solution;


    // ---------------------------------------------------------
    // Test Case 1
    // n = 6
    //
    // 6 is not prime.
    // 7 is prime and palindrome.
    //
    // Answer = 7
    // ---------------------------------------------------------
    int n1 = 6;

    cout << "Input: " << n1 << endl;
    cout << "Output: "
         << solution.primePalindrome(n1)
         << endl;


    cout << endl;


    // ---------------------------------------------------------
    // Test Case 2
    // n = 8
    //
    // 8 → not prime
    // 9 → palindrome but not prime
    // 10 → not palindrome
    // 11 → palindrome + prime
    //
    // Answer = 11
    // ---------------------------------------------------------
    int n2 = 8;

    cout << "Input: " << n2 << endl;
    cout << "Output: "
         << solution.primePalindrome(n2)
         << endl;


    cout << endl;


    // ---------------------------------------------------------
    // Test Case 3
    // n = 13
    //
    // The next prime palindrome is 101.
    //
    // Answer = 101
    // ---------------------------------------------------------
    int n3 = 13;

    cout << "Input: " << n3 << endl;
    cout << "Output: "
         << solution.primePalindrome(n3)
         << endl;


    // Program finished successfully.
    return 0;
}