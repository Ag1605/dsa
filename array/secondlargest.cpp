#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the second largest DISTINCT element
    // in the given vector
    int secondLargestElement(vector<int> &nums)
    {

        // If the array has fewer than 2 elements,
        // a second largest element cannot exist.
        if (nums.size() < 2)
        {
            return -1;
        }

        // l = largest element found so far
        // sl = second largest element found so far
        //
        // INT_MIN is used initially because it is
        // the smallest possible value of an int.
        int l = INT_MIN;
        int sl = INT_MIN;

        // Traverse through the entire array
        for (int i = 0; i < nums.size(); i++)
        {

            // Case 1:
            // Current element is greater than the largest
            // element found so far.
            if (nums[i] > l)
            {

                // The previous largest becomes
                // the second largest.
                sl = l;

                // Current element becomes the new largest.
                l = nums[i];
            }

            // Case 2:
            // Current element is smaller than largest
            // but greater than second largest.
            //
            // nums[i] < l ensures that we don't consider
            // the largest element itself as second largest.
            else if (nums[i] > sl && nums[i] < l)
            {

                // Update second largest.
                sl = nums[i];
            }
        }

        // If sl is still INT_MIN, it means that we did not
        // find any distinct second largest element.
        //
        // Example:
        // [5, 5, 5]
        //
        // Largest = 5
        // No distinct second largest exists.
        if (sl == INT_MIN)
        {
            return -1;
        }

        // Return the second largest element.
        return sl;
    }
};

int main()
{

    // Example array
    vector<int> nums = {3, 3, 6, 1};

    // Create object of Solution class
    Solution obj;

    // Call the function
    int answer = obj.secondLargestElement(nums);

    // Print result
    cout << "Second largest element = " << answer << endl;

    return 0;
}