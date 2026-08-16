#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate the array by ONE position to the LEFT.
    //
    // Example:
    // Input  : [1, 2, 3, 4, 5]
    // Output : [2, 3, 4, 5, 1]
    void rotateArrayByOne(vector<int> &nums)
    {

        // Store the first element temporarily.
        //
        // We need to save it because during shifting
        // it will be overwritten.
        //
        // Example:
        // [1, 2, 3, 4, 5]
        //  ↑
        // temp = 1
        int temp = nums[0];

        // Start from index 1 and move every element
        // one position towards the LEFT.
        //
        // nums[i] is copied to nums[i - 1].
        //
        // Example:
        // nums[1] -> nums[0]
        // nums[2] -> nums[1]
        // nums[3] -> nums[2]
        // nums[4] -> nums[3]
        for (int i = 1; i < nums.size(); ++i)
        {

            // Move current element one position left.
            nums[i - 1] = nums[i];
        }

        // Put the original first element at the
        // last position.
        //
        // Example:
        // [2, 3, 4, 5, _]
        //              ↑
        //          nums[n-1]
        //
        // Put temp = 1 here:
        // [2, 3, 4, 5, 1]
        nums[nums.size() - 1] = temp;
    }
};

int main()
{

    // Create the input array.
    vector<int> nums = {1, 2, 3, 4, 5};

    // Create an object of Solution class.
    Solution obj;

    // Rotate the array by one position.
    obj.rotateArrayByOne(nums);

    // Print the rotated array.
    cout << "Array after left rotation by one: ";

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}