#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {

        // Tracks the current bracket balance
        int balance = 0;

        // Stores the maximum number of unmatched closing brackets
        int maxImbalance = 0;

        // Traverse the string from left to right
        for (int i = 0; i < s.size(); i++) {

            // Opening bracket increases the balance
            if (s[i] == '[') {
                balance++;
            }
            // Closing bracket decreases the balance
            else {
                balance--;
            }

            // If balance is negative, there are unmatched ']'
            // Example: balance = -3 means 3 unmatched ']'
            // -balance converts -3 into positive 3
            // max() keeps the largest imbalance found so far
            maxImbalance = max(maxImbalance, -balance);
        }

        // One swap can fix up to two unmatched closing brackets
        // Integer division rounds down
        return (maxImbalance + 1) / 2;
    }
};

int main() {

    Solution obj;

    string s = "]]][[[";

    // Call the function and display the minimum swaps
    cout << "Input: " << s << endl;
    cout << "Minimum swaps: " << obj.minSwaps(s) << endl;

    return 0;
}