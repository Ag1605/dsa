#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function checks whether the array is
    // sorted in non-decreasing order and then rotated.
    bool check(vector<int> &nums)
    {

        // count stores how many times the order
        // decreases while moving through the array.
        int count = 0;

        // Store the size of the array.
        int n = nums.size();

        // Traverse every element of the array.
        for (int i = 0; i < n; i++)
        {

            // Compare the current element with the next element.
            //
            // (i + 1) % n is used so that:
            // when i = n - 1,
            // (i + 1) % n = 0
            //
            // Therefore, the last element is compared
            // with the first element.
            if (nums[i] > nums[(i + 1) % n])
            {

                // We found a point where the increasing
                // order breaks.
                count++;
            }
        }

        // For a sorted and rotated array, there can be
        // at most ONE place where:
        //
        // nums[i] > nums[i + 1]
        //
        // If count is 0:
        // The array is simply sorted.
        //
        // If count is 1:
        // The array is sorted and rotated.
        //
        // If count > 1:
        // The array cannot be sorted and rotated.
        return count <= 1;
    }
};

int main()
{

    // Example 1
    vector<int> nums = {3, 4, 5, 1, 2};

    // Create object of Solution class
    Solution obj;

    // Call check() function
    bool answer = obj.check(nums);

    // Print result
    if (answer)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}