#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the length of the longest
    // subarray whose sum is equal to k.
    //
    // Example:
    // nums = {-1, 1, 1}
    // k = 1
    //
    // Possible subarrays:
    // [-1]       -> sum = -1
    // [-1, 1]    -> sum = 0
    // [-1, 1, 1] -> sum = 1  -> length = 3
    //
    // Answer = 3
    int longestSubarray(vector<int> &nums, int k)
    {

        // n = size of the array.
        int n = nums.size();

        // This map stores:
        //
        // prefix sum -> first index where that
        // prefix sum appeared.
        //
        // Example:
        // If prefix sum 5 first appears at index 2:
        //
        // preSumMap[5] = 2
        map<int, int> preSumMap;

        // 'sum' stores the prefix sum while
        // traversing the array.
        int sum = 0;

        // Stores the maximum length found so far.
        int maxLen = 0;

        // Traverse the array.
        for (int i = 0; i < n; i++)
        {

            // Add the current element to the
            // prefix sum.
            sum += nums[i];

            // ------------------------------------------------
            // CASE 1:
            // The entire subarray from index 0 to i
            // has sum equal to k.
            // ------------------------------------------------
            //
            // Example:
            // nums = [1, 2]
            // k = 3
            //
            // sum = 3
            //
            // Subarray [0...i] has sum k.
            if (sum == k)
            {

                // Length of subarray from index 0 to i
                // is i + 1.
                maxLen = max(maxLen, i + 1);
            }

            // ------------------------------------------------
            // CASE 2:
            // Find whether an earlier prefix sum exists
            // such that the remaining part has sum k.
            // ------------------------------------------------
            //
            // We know:
            //
            // current prefix sum = sum
            //
            // We want:
            //
            // subarray sum = k
            //
            // Therefore:
            //
            // previous prefix sum = sum - k
            int rem = sum - k;

            // Check whether this required prefix sum
            // appeared earlier.
            if (preSumMap.find(rem) != preSumMap.end())
            {

                // Suppose:
                //
                // current index = i
                // previous prefix sum was found at index j
                //
                // Then the subarray is:
                //
                // j + 1 ........ i
                //
                // Its length is:
                //
                // i - j
                int len = i - preSumMap[rem];

                // Update maximum length.
                maxLen = max(maxLen, len);
            }

            // ------------------------------------------------
            // Store the prefix sum in the map.
            // ------------------------------------------------
            //
            // IMPORTANT:
            // We store the prefix sum ONLY if it has
            // not appeared before.
            //
            // Why?
            //
            // We want the earliest index because an
            // earlier index gives us a LONGER subarray.
            if (preSumMap.find(sum) == preSumMap.end())
            {

                // Store:
                //
                // prefix sum -> index
                preSumMap[sum] = i;
            }
        }

        // Return the length of the longest subarray.
        return maxLen;
    }
};

int main()
{

    // Input array.
    vector<int> a = {-1, 1, 1};

    // Required sum.
    int k = 1;

    // Create an object of Solution class.
    Solution solution;

    // Call the function.
    int len = solution.longestSubarray(a, k);

    // Print the answer.
    cout << "The length of the longest subarray is: "
         << len << endl;

    return 0;
}