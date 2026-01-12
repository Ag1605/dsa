#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
QUESTION:
You are given an array of integers.
Your task is to find the length of the longest sequence of consecutive numbers.

Consecutive numbers means:
numbers that come one after another without any gap.

Example:
Input:  [100, 4, 200, 1, 3, 2]
Output: 4

Explanation:
The longest consecutive sequence is 1, 2, 3, 4
So the length is 4.
*/

int longestConsecutive(vector<int>& nums) {

    // If the array is empty, return 0
    if (nums.size() == 0)
        return 0;

    // Store all numbers in an unordered_set for fast lookup
    unordered_set<int> s;
    for (int x : nums) {
        s.insert(x);
    }

    int longest = 0;

    // Loop through each number in the set
    for (int x : s) {

        // Check if this number is the start of a sequence
        // (means the previous number does not exist)
        if (s.find(x - 1) == s.end()) {

            int current = x;
            int count = 1;

            // Count consecutive numbers
            while (s.find(current + 1) != s.end()) {
                current++;
                count++;
            }

            // Update the longest sequence length
            if (count > longest) {
                longest = count;
            }
        }
    }

    return longest;
}

int main() {

    // Input array
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Function call
    int result = longestConsecutive(nums);

    // Output
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
