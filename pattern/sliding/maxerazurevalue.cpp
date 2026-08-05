#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        // ----------------------------------------------------
        // unordered_set stores all unique elements
        // currently present inside the sliding window.
        // It helps us check duplicates in O(1) time.
        // ----------------------------------------------------
        unordered_set<int> st;

        // Left pointer of the sliding window
        int left = 0;

        // Sum of the current window
        int sum = 0;

        // Maximum sum of any unique subarray
        int ans = 0;

        // ----------------------------------------------------
        // Expand the window using the right pointer.
        // ----------------------------------------------------
        for (int right = 0; right < nums.size(); right++)
        {
            // ------------------------------------------------
            // If nums[right] is already inside the window,
            // keep shrinking the window until it becomes unique.
            // ------------------------------------------------
            while (st.count(nums[right]))
            {
                // Remove the leftmost element
                st.erase(nums[left]);

                // Update the window sum
                sum -= nums[left];

                // Move left pointer forward
                left++;
            }

            // ------------------------------------------------
            // nums[right] is now unique.
            // Add it to the window.
            // ------------------------------------------------
            st.insert(nums[right]);

            // Add its value to the current window sum
            sum += nums[right];

            // Update the maximum sum
            ans = max(ans, sum);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 2, 4, 5, 6};

    cout << "Maximum Unique Subarray Sum = "
         << obj.maximumUniqueSubarray(nums);

    return 0;
}