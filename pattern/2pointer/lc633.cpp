#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:

    bool judgeSquareSum(int c) {

        // 'left' starts from 0.
        //
        // We are looking for:
        //
        // a² + b² = c
        //
        // So 'left' represents a possible value of 'a'.
        long long left = 0;

        // 'right' starts from sqrt(c).
        //
        // Why sqrt(c)?
        //
        // Because if:
        //
        // a² + b² = c
        //
        // then neither a nor b can be greater than sqrt(c).
        //
        // Example:
        // c = 25
        // sqrt(25) = 5
        //
        // So we start with:
        // left = 0
        // right = 5
        long long right = sqrt(c);


        // Continue while the two pointers
        // have not crossed each other.
        while (left <= right) {

            // Calculate:
            //
            // left² + right²
            //
            // We use long long to avoid integer overflow
            // when calculating left * left and right * right.
            long long sum = left * left + right * right;


            // If the sum is exactly equal to c,
            // we found two numbers whose squares
            // add up to c.
            //
            // Example:
            // c = 25
            //
            // left = 0, right = 5
            // 0² + 5² = 25
            //
            // Therefore return true.
            if (sum == c) {
                return true;
            }


            // If the sum is smaller than c,
            // we need to increase the sum.
            //
            // Increasing 'left' increases:
            //
            // left²
            //
            // Therefore move left pointer forward.
            if (sum < c) {
                left++;
            }


            // If the sum is greater than c,
            // we need to decrease the sum.
            //
            // Decreasing 'right' decreases:
            //
            // right²
            //
            // Therefore move right pointer backward.
            else {
                right--;
            }
        }


        // If the loop finishes without finding
        // a valid combination, no such numbers exist.
        return false;
    }
};


int main() {

    // Example:
    // 5 = 1² + 2²
    //
    // Therefore the answer should be true.
    int c = 5;

    // Create object of Solution class.
    Solution obj;

    // Call judgeSquareSum().
    bool result = obj.judgeSquareSum(c);

    // Print result.
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}