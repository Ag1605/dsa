#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // n = length of the haystack string
        int n = haystack.size();

        // m = length of the needle string
        int m = needle.size();

        /*
            We try every possible starting position in haystack.

            Example:
            haystack = "sadbutsad"
            needle   = "sad"

            We check:
            i = 0 -> "sad" matches -> return 0

            The last possible starting position is n - m.

            Why?
            If n = 9 and m = 3:
            last starting index = 9 - 3 = 6
        */
        for (int i = 0; i <= n - m; i++) {

            // j represents the current character of needle
            int j = 0;

            /*
                Compare needle with haystack starting from index i.

                haystack[i + j]
                needle[j]

                We continue while:
                1. j is inside needle
                2. Both characters are equal
            */
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            /*
                If j becomes equal to m, it means that
                all characters of needle matched.

                Therefore, i is the starting index of needle
                inside haystack.
            */
            if (j == m) {
                return i;
            }
        }

        /*
            If we finish the loop without finding needle,
            return -1.
        */
        return -1;
    }
};


int main() {

    // Create an object of Solution class
    Solution sol;

    // Example input
    string haystack = "sadbutsad";
    string needle = "sad";

    // Call strStr() and store the answer
    int result = sol.strStr(haystack, needle);

    // Print the result
    cout << "Index: " << result << endl;

    return 0;
}