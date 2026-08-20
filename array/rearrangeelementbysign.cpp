#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to rearrange the array so that:
    // 1. Positive and negative numbers appear alternately.
    // 2. The first element is positive.
    // 3. The relative order of positive numbers is maintained.
    // 4. The relative order of negative numbers is maintained.
    vector<int> rearrangeArray(vector<int>& nums) {

        // Store the size of the input array.
        int n = nums.size();

        // Create an answer array of the same size.
        vector<int> ans(n);

        // 'pos' represents the index where the next
        // positive number should be placed.
        //
        // Positive numbers go to:
        // 0, 2, 4, 6, ...
        int pos = 0;

        // 'neg' represents the index where the next
        // negative number should be placed.
        //
        // Negative numbers go to:
        // 1, 3, 5, 7, ...
        int neg = 1;

        // Traverse every number in the input array.
        for (int ch : nums) {

            // If the current number is positive,
            // put it at the current positive index.
            if (ch > 0) {

                ans[pos] = ch;

                // Move to the next positive position.
                // We increase by 2 because positive numbers
                // occupy only even indices.
                pos += 2;
            }

            // Otherwise, the number is negative.
            else {

                // Put the negative number at the current
                // negative index.
                ans[neg] = ch;

                // Move to the next negative position.
                // Negative numbers occupy odd indices.
                neg += 2;
            }
        }

        // Return the rearranged array.
        return ans;
    }
};


int main() {

    // Example input
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    // Create an object of Solution class.
    Solution obj;

    // Call the rearrangeArray function.
    vector<int> answer = obj.rearrangeArray(nums);

    // Print the rearranged array.
    cout << "Rearranged Array: ";

    for (int num : answer) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}