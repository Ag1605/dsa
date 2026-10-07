#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {

        // Start from the last digit
        // because addition starts from the units place
        for (int i = digits.size() - 1; i >= 0; i--) {

            // If the current digit is less than 9,
            // we can simply increase it by 1
            // and return the answer.
            //
            // Example:
            // [1, 2, 3]
            //       ^
            // 3 becomes 4
            // Answer = [1, 2, 4]
            if (digits[i] < 9) {

                digits[i]++;

                return digits;
            }

            // If the digit is 9,
            // adding 1 makes it 0
            // and we have to carry 1 to the previous digit.
            //
            // Example:
            // [1, 2, 9]
            //       9 + 1 = 10
            // So:
            // 9 becomes 0
            // carry goes to 2
            digits[i] = 0;
        }

        // If the loop finishes, it means
        // every digit was 9.
        //
        // Example:
        // [9, 9, 9]
        //
        // After the loop:
        // [0, 0, 0]
        //
        // We need to add 1 at the beginning:
        // [1, 0, 0, 0]
        digits.insert(digits.begin(), 1);

        return digits;
    }
};


int main() {

    // Input array representing the number 129
    vector<int> digits = {1, 2, 9};

    // Create an object of Solution class
    Solution obj;

    // Call plusOne()
    vector<int> result = obj.plusOne(digits);

    // Print the result
    cout << "Result: ";

    for (int digit : result) {
        cout << digit << " ";
    }

    cout << endl;

    return 0;
}