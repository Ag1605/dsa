#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the length of the longest
    // subarray whose sum is equal to k.
    //
    // IMPORTANT:
    // This sliding window approach works when
    // all elements are NON-NEGATIVE.
    //
    // Example:
    // nums = [1, 2, 1, 1, 1]
    // k = 3
    //
    // Longest subarray with sum 3:
    // [1, 1, 1]
    //
    // Answer = 3

    int longestSubarray(vector<int> &nums, int k)
    {

        // 'left' represents the left boundary
        // of our current window.
        int left = 0;

        // Stores the sum of elements inside
        // the current window.
        int sum = 0;

        // Stores the maximum length found so far.
        int maxLength = 0;

        // 'right' represents the right boundary
        // of our current window.
        //
        // We expand the window by moving right.
        for (int right = 0; right < nums.size(); right++)
        {

            // Add the current element to the
            // current window.
            sum += nums[right];

            // If the sum becomes greater than k,
            // we need to shrink the window.
            //
            // We remove elements from the LEFT
            // until sum becomes <= k.
            while (sum > k)
            {

                // Remove the leftmost element
                // from the current window.
                sum -= nums[left];

                // Move left pointer forward.
                left++;
            }

            // If the current window has sum exactly k,
            // calculate its length.
            if (sum == k)
            {

                // Window is:
                //
                // left ........ right
                //
                // Number of elements:
                //
                // right - left + 1
                maxLength = max(maxLength, right - left + 1);
            }
        }

        // Return the longest valid subarray length.
        return maxLength;
    }
};

int main()
{

    // IMPORTANT:
    // This array contains only non-negative numbers.
    vector<int> nums = {1, 2, 1, 1, 1};

    // Required sum.
    int k = 3;

    // Create object of Solution class.
    Solution obj;

    // Find the longest subarray.
    int answer = obj.longestSubarray(nums, k);

    // Print the answer.
    cout << "Longest subarray length = " << answer << endl;

    return 0;
}