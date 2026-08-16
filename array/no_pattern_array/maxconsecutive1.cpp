#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of
    // consecutive 1s in the array.
    //
    // Example:
    // nums = [1, 1, 0, 1, 1, 1]
    //
    // Maximum consecutive 1s = 3
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        // 'count' stores the number of consecutive 1s
        // in the current sequence.
        int count = 0;

        // 'ans' stores the maximum number of consecutive
        // 1s found so far.
        int ans = 0;

        // Traverse through every element of the array.
        for (int i = 0; i < nums.size(); i++)
        {

            // If the current element is 1,
            // increase the current consecutive count.
            if (nums[i] == 1)
            {

                count++;

                // Update ans if the current count
                // is greater than the previous maximum.
                ans = max(count, ans);
            }

            // If the current element is 0,
            // the consecutive sequence of 1s is broken.
            else
            {
                count = 0;
            }
        }

        // Return the maximum number of consecutive 1s.
        return ans;
    }
};

int main()
{

    // Create the input array.
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};

    // Create an object of Solution class.
    Solution obj;

    // Call the function.
    int answer = obj.findMaxConsecutiveOnes(nums);

    // Print the result.
    cout << "Maximum consecutive ones = " << answer << endl;

    return 0;
}