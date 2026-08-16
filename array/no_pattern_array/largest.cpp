#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find and return the largest element
    // present in the given vector
    int largestElement(vector<int> &nums)
    {

        // Assume the first element is the largest initially.
        // Example: nums = [3, 3, 6, 1]
        // Initially, max = 3
        int max = nums[0];

        // Traverse through every element of the array.
        // We can start from index 0 as well, although
        // index 0 is already stored in max.
        for (int i = 0; i < nums.size(); i++)
        {

            // If the current element is greater than
            // our current maximum value...
            if (nums[i] > max)
            {

                // Update max with the current element.
                max = nums[i];
            }
        }

        // After checking all elements, max contains
        // the largest element of the array.
        return max;
    }
};

int main()
{

    // Create an array/vector
    vector<int> nums = {3, 3, 6, 1};

    // Create an object of Solution class
    Solution obj;

    // Call the largestElement() function
    // and store the returned answer.
    int answer = obj.largestElement(nums);

    // Print the largest element
    cout << "Largest element = " << answer << endl;

    return 0;
}