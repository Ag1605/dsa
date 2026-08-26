#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    // ---------------------------------------------------------
    // FUNCTION: expand()
    //
    // This function starts from the middle of a possible
    // palindrome and expands outward.
    //
    // Example:
    //
    //      b a b
    //        ^
    //      center
    //
    // We compare:
    //      left character == right character
    //
    // If they are equal, we continue expanding.
    //
    // For example:
    //
    //      "babad"
    //         ^
    //         i = 1
    //
    // Start:
    //      left = 1 ('a')
    //      right = 1 ('a')
    //
    // Expand:
    //      "bab"
    //
    // Then:
    //      left = -1? No, after checking "bab",
    //      we move outside the palindrome.
    //
    // The function returns the length of the palindrome.
    // ---------------------------------------------------------

    int expand(string &s, int left, int right) {

        // Keep expanding while:
        //
        // 1. left is inside the string
        // 2. right is inside the string
        // 3. characters on both sides are equal
        //
        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {

            // Move left one position to the left
            left--;

            // Move right one position to the right
            right++;
        }

        // IMPORTANT:
        //
        // When the while loop stops,
        // left and right are already OUTSIDE
        // the palindrome.
        //
        // Example:
        //
        //        b a b
        //        0 1 2
        //
        // After expansion:
        //
        // left  = -1
        // right = 3
        //
        // Length:
        //
        // right - left - 1
        //
        // = 3 - (-1) - 1
        // = 3
        //
        return right - left - 1;
    }


    // ---------------------------------------------------------
    // FUNCTION: longestPalindrome()
    //
    // Finds the longest palindromic substring.
    //
    // Important idea:
    //
    // Every palindrome has a CENTER.
    //
    // There are TWO types of centers:
    //
    // 1. Odd length palindrome
    //
    //       b a b
    //         ^
    //       center
    //
    //    Center is one character.
    //
    //
    // 2. Even length palindrome
    //
    //       a b b a
    //         ^ ^
    //       center
    //
    //    Center is BETWEEN two characters.
    //
    // Therefore, for every index i, we check BOTH cases.
    // ---------------------------------------------------------

    string longestPalindrome(string s) {

        // 'start' stores the starting index of our
        // longest palindrome found so far.
        //
        // Initially we assume the answer starts at 0.
        int start = 0;

        // 'end' stores the ending index of our
        // longest palindrome found so far.
        //
        // Initially:
        //
        // start = 0
        // end   = 0
        //
        // So the current answer has length 1.
        int end = 0;


        // Try every character as a possible center.
        //
        // Example:
        //
        // s = "babad"
        //
        // i = 0
        // i = 1
        // i = 2
        // i = 3
        // i = 4
        //
        for (int i = 0; i < s.length(); i++) {


            // -------------------------------------------------
            // CASE 1: ODD LENGTH PALINDROME
            // -------------------------------------------------
            //
            // We use the SAME character as the center.
            //
            // Example:
            //
            //       b a b
            //         ^
            //         i
            //
            // So:
            //
            // left  = i
            // right = i
            //
            int len1 = expand(s, i, i);


            // -------------------------------------------------
            // CASE 2: EVEN LENGTH PALINDROME
            // -------------------------------------------------
            //
            // Here the center is BETWEEN two characters.
            //
            // Example:
            //
            //       a b b a
            //         ^ ^
            //         i i+1
            //
            // So:
            //
            // left  = i
            // right = i + 1
            //
            int len2 = expand(s, i, i + 1);


            // Take whichever palindrome is longer:
            //
            // odd palindrome length
            // OR
            // even palindrome length
            //
            int len = max(len1, len2);


            // -------------------------------------------------
            // CHECK WHETHER THIS PALINDROME IS LONGER
            // THAN OUR CURRENT ANSWER
            // -------------------------------------------------
            //
            // Current answer length:
            //
            // end - start + 1
            //
            // Example:
            //
            // start = 1
            // end = 3
            //
            // length = 3 - 1 + 1
            //        = 3
            //
            if (len > end - start + 1) {


                // -------------------------------------------------
                // CALCULATE STARTING INDEX
                // -------------------------------------------------
                //
                // Formula:
                //
                // start = i - (len - 1) / 2
                //
                // Why?
                //
                // We know:
                // i = center
                // len = palindrome length
                //
                // We move backwards from the center
                // to find the starting position.
                //
                start = i - (len - 1) / 2;


                // -------------------------------------------------
                // CALCULATE ENDING INDEX
                // -------------------------------------------------
                //
                // Formula:
                //
                // end = i + len / 2
                //
                // We move forward from the center
                // to find the ending position.
                //
                end = i + len / 2;
            }
        }


        // ---------------------------------------------------------
        // RETURN THE LONGEST PALINDROME
        // ---------------------------------------------------------
        //
        // substr(start, length)
        //
        // We know:
        //
        // start = starting index
        //
        // length = end - start + 1
        //
        // Example:
        //
        // s = "babad"
        //
        // start = 0
        // end   = 2
        //
        // length = 2 - 0 + 1
        //        = 3
        //
        // s.substr(0, 3)
        // = "bab"
        //
        return s.substr(start, end - start + 1);
    }
};


// -------------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------------
//
// LeetCode normally does NOT require main().
//
// But we are writing main() here so that you can run the
// program yourself in VS Code / online compiler.
//
// -------------------------------------------------------------

int main() {

    // Create an object of Solution class
    Solution solution;


    // Input string
    string s;

    cout << "Enter a string: ";
    cin >> s;


    // Call longestPalindrome()
    //
    // The function returns the longest palindromic substring.
    string answer = solution.longestPalindrome(s);


    // Print the answer
    cout << "Longest Palindromic Substring: "
         << answer << endl;


    return 0;
}N