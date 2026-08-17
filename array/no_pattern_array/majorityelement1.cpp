#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // ----------------------------------------------------
        // candidate = current element that we think
        //             could be the majority element
        //
        // count = strength/support of our candidate
        // ----------------------------------------------------

        int candidate = 0;
        int count = 0;


        // ----------------------------------------------------
        // Traverse every element of the array
        // ----------------------------------------------------

        for (int num : nums) {

            // ------------------------------------------------
            // If count becomes 0, our previous candidate
            // has been cancelled out.
            //
            // So we choose the current number as
            // the new candidate.
            // ------------------------------------------------

            if (count == 0) {
                candidate = num;
            }


            // ------------------------------------------------
            // If current number is the same as candidate,
            // increase the count.
            //
            // This means:
            // candidate gets +1 support.
            // ------------------------------------------------

            if (num == candidate) {
                count++;
            }


            // ------------------------------------------------
            // If current number is different from candidate,
            // decrease the count.
            //
            // This means:
            // one occurrence of candidate is cancelled
            // by a different number.
            // ------------------------------------------------

            else {
                count--;
            }
        }


        // ----------------------------------------------------
        // At the end, candidate is the majority element.
        //
        // This works because the majority element appears
        // MORE THAN n/2 times.
        // ----------------------------------------------------

        return candidate;
    }
};


int main() {

    // Example array
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Create object of Solution class
    Solution sol;

    // Find majority element
    int answer = sol.majorityElement(nums);

    // Print the answer
    cout << "Majority Element: " << answer << endl;

    return 0;
}