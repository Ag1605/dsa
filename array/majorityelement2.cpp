#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find all elements that appear
    // more than n/3 times in the array.
    //
    // There can be at most TWO such elements.
    vector<int> majorityElement(vector<int>& nums) {

        // candidate1 and candidate2 store
        // the two possible majority elements.
        int candidate1 = 0;
        int candidate2 = 0;

        // count1 and count2 store the voting balance
        // for candidate1 and candidate2.
        int count1 = 0;
        int count2 = 0;


        // ------------------------------------------------
        // STEP 1: FIND TWO POTENTIAL CANDIDATES
        // ------------------------------------------------

        // Traverse every number in the array.
        for (int num : nums) {

            // If current number is candidate1,
            // increase candidate1's vote.
            if (num == candidate1) {
                count1++;
            }

            // Otherwise, if current number is candidate2,
            // increase candidate2's vote.
            else if (num == candidate2) {
                count2++;
            }

            // If candidate1 has no votes,
            // make current number candidate1.
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }

            // Otherwise, if candidate2 has no votes,
            // make current number candidate2.
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }

            // If current number is different from both
            // candidates and both candidates have votes,
            // cancel one vote from each candidate.
            else {
                count1--;
                count2--;
            }
        }


        // ------------------------------------------------
        // STEP 2: VERIFY THE CANDIDATES
        // ------------------------------------------------

        // The first pass only gives us potential candidates.
        //
        // We must count their actual frequencies
        // in the original array.
        count1 = 0;
        count2 = 0;


        // Traverse the array again.
        for (int num : nums) {

            // Count occurrences of candidate1.
            if (num == candidate1) {
                count1++;
            }

            // Count occurrences of candidate2.
            if (num == candidate2) {
                count2++;
            }
        }


        // Vector to store the final answer.
        vector<int> ans;

        // Store the size of the array.
        int n = nums.size();


        // Check whether candidate1 appears
        // more than n/3 times.
        if (count1 > n / 3) {
            ans.push_back(candidate1);
        }


        // Check candidate2.
        //
        // candidate2 must be different from candidate1.
        // Otherwise, we would add the same number twice.
        if (count2 > n / 3 && candidate2 != candidate1) {
            ans.push_back(candidate2);
        }


        // Return the final majority elements.
        return ans;
    }
};


int main() {

    // Example input.
    vector<int> nums = {
        3, 2, 3
    };

    // Create an object of Solution class.
    Solution obj;

    // Find elements appearing more than n/3 times.
    vector<int> answer = obj.majorityElement(nums);


    // Print the answer.
    cout << "Majority Elements: ";

    for (int num : answer) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}