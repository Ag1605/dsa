#include <iostream>

using namespace std;

class Solution {
public:

    bool isPerfectSquare(int num) {

        // We are searching for a number 'x' such that:
        //
        // x * x = num
        //
        // The smallest possible x is 1.
        long long left = 1;

        // The largest possible x is num.
        //
        // For example:
        // num = 16
        // possible answer is between 1 and 16.
        //
        // We could optimize this to sqrt(num),
        // but using num still works correctly.
        long long right = num;


        // Continue binary search while
        // there is still a valid search range.
        while (left <= right) {

            // Find the middle value.
            //
            // This form prevents integer overflow
            // compared with:
            //
            // (left + right) / 2
            long long mid = left + (right - left) / 2;


            // Calculate mid².
            //
            // long long is used because mid * mid
            // can become larger than the int range.
            long long square = mid * mid;


            // If mid² is exactly equal to num,
            // then num is a perfect square.
            //
            // Example:
            // num = 16
            // mid = 4
            //
            // 4 * 4 = 16
            //
            // Therefore return true.
            if (square == num) {
                return true;
            }


            // If mid² is smaller than num,
            // then mid is too small.
            //
            // We need to search on the RIGHT side.
            //
            // Example:
            // num = 16
            // mid = 3
            //
            // 3² = 9
            // 9 < 16
            //
            // So answer must be greater than 3.
            else if (square < num) {
                left = mid + 1;
            }


            // If mid² is greater than num,
            // then mid is too large.
            //
            // We need to search on the LEFT side.
            //
            // Example:
            // num = 16
            // mid = 5
            //
            // 5² = 25
            // 25 > 16
            //
            // So answer must be smaller than 5.
            else {
                right = mid - 1;
            }
        }


        // If the binary search finishes without finding
        // a number whose square equals num,
        // then num is NOT a perfect square.
        return false;
    }
};


int main() {

    // Example input
    int num = 16;

    // Create object of Solution class.
    Solution obj;

    // Call the function.
    bool result = obj.isPerfectSquare(num);

    // Print result.
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}