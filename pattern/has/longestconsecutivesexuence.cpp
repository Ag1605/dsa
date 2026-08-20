#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find the length of the longest
    // consecutive sequence in the array.
    int longestConsecutive(vector<int>& nums) {

        // Put all elements into an unordered_set.
        //
        // Why?
        // unordered_set gives average O(1) lookup.
        //
        // It also automatically removes duplicates.
        unordered_set<int> st(nums.begin(), nums.end());

        // Stores the length of the longest
        // consecutive sequence found so far.
        int longest = 0;


        // Traverse through every UNIQUE number in the set.
        for (int num : st) {

            // Check if 'num' is the START of a sequence.
            //
            // If num - 1 does NOT exist,
            // then there is no smaller consecutive number
            // before num.
            //
            // Therefore, num must be the first element
            // of a consecutive sequence.
            if (st.find(num - 1) == st.end()) {

                // Current number in the sequence.
                int current = num;

                // We already have 'num',
                // so the initial length is 1.
                int length = 1;


                // Keep checking whether the next consecutive
                // number exists.
                //
                // Example:
                // If current = 4,
                // check whether 5 exists.
                //
                // If 5 exists:
                // current becomes 5
                // length becomes 2
                //
                // Then check 6, 7, etc.
                while (st.find(current + 1) != st.end()) {

                    current++;
                    length++;
                }


                // Compare the current sequence length
                // with the longest sequence found so far.
                longest = max(longest, length);
            }
        }


        // Return the length of the longest
        // consecutive sequence.
        return longest;
    }
};


int main() {

    // Example input.
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Create an object of Solution class.
    Solution obj;

    // Call the function.
    int answer = obj.longestConsecutive(nums);

    // Print the answer.
    cout << "Longest Consecutive Sequence Length = "
         << answer << endl;

    return 0;
}