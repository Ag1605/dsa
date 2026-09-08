#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        // i is used to traverse version1
        int i = 0;

        // j is used to traverse version2
        int j = 0;

        // n = length of version1
        int n = version1.size();

        // m = length of version2
        int m = version2.size();

        /*
            We continue until we have processed
            all the parts of both version strings.

            Example:

            version1 = "1.2.10"
            version2 = "1.2.3"

            Parts to compare:

            1  vs  1
            2  vs  2
            10 vs  3
        */
        while (i < n || j < m) {

            /*
                num1 will store the current numeric part
                of version1.

                Example:
                version1 = "1.2.10"

                First iteration -> num1 = 1
                Second iteration -> num1 = 2
                Third iteration -> num1 = 10
            */
            long long num1 = 0;

            /*
                Read characters from version1 until:

                1. We reach the end of the string
                OR
                2. We encounter '.'

                For example:

                "123.45"

                We read:
                '1' -> '2' -> '3'

                Then stop at '.'
            */
            while (i < n && version1[i] != '.') {

                /*
                    Convert the character into a digit.

                    Suppose version1[i] = '5'

                    '5' - '0' = 5

                    We then build the complete number.

                    Example: "123"

                    Initially:
                    num1 = 0

                    Read '1':
                    num1 = 0 * 10 + 1 = 1

                    Read '2':
                    num1 = 1 * 10 + 2 = 12

                    Read '3':
                    num1 = 12 * 10 + 3 = 123
                */
                num1 = num1 * 10 + (version1[i] - '0');

                // Move to the next character
                i++;
            }


            /*
                num2 will store the current numeric part
                of version2.

                We do exactly the same thing for version2.
            */
            long long num2 = 0;

            /*
                Read characters from version2 until:

                1. We reach the end
                OR
                2. We encounter '.'
            */
            while (j < m && version2[j] != '.') {

                /*
                    Convert character to digit and build
                    the complete numeric value.

                    Example:
                    "123"

                    1 -> num2 = 1
                    2 -> num2 = 12
                    3 -> num2 = 123
                */
                num2 = num2 * 10 + (version2[j] - '0');

                // Move to the next character
                j++;
            }


            /*
                Now compare the current revision numbers.

                Example:

                version1 = "1.5"
                version2 = "1.3"

                First:
                num1 = 1
                num2 = 1

                They are equal, so continue.

                Second:
                num1 = 5
                num2 = 3

                5 > 3, therefore version1 is greater.
            */

            if (num1 < num2) {
                return -1;
            }

            if (num1 > num2) {
                return 1;
            }


            /*
                If we reach here, num1 == num2.

                Now we need to skip the '.' in version1.

                Example:

                version1 = "1.2.3"
                             ^
                             i is currently here

                Move i one position forward to skip '.'
            */
            if (i < n && version1[i] == '.') {
                i++;
            }


            /*
                Do the same thing for version2.

                Skip the '.' after the current revision.
            */
            if (j < m && version2[j] == '.') {
                j++;
            }
        }


        /*
            If we finish the entire loop without finding
            any different revision number, both versions
            are considered equal.

            Example:

            "1.01"
            "1.001"

            Both represent:

            1.1

            Therefore return 0.
        */
        return 0;
    }
};


int main() {

    // Create an object of Solution class
    Solution sol;

    // Example version numbers
    string version1 = "1.2.10";
    string version2 = "1.2.3";

    // Call compareVersion() and store the result
    int result = sol.compareVersion(version1, version2);

    // Print the result
    cout << "Result: " << result << endl;

    return 0;
}