#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate the array to the LEFT by k positions.
    //
    // Example:
    // nums = [1, 2, 3, 4, 5, 6]
    // k = 2
    //
    // Output:
    // [3, 4, 5, 6, 1, 2]
    void rotateArray(vector<int> &nums, int k)
    {

        // Store the size of the array.
        int n = nums.size();

        // If the array is empty, we cannot perform
        // modulo operation with n = 0.
        if (n == 0)
        {
            return;
        }

        // If k is greater than n, reduce it.
        //
        // Example:
        // n = 6, k = 8
        //
        // 8 % 6 = 2
        //
        // Rotating 8 positions is the same as
        // rotating 2 positions.
        k = k % n;

        // ------------------------------------------------
        // STEP 1: Reverse the first k elements
        // ------------------------------------------------
        //
        // Original:
        // [1, 2 | 3, 4, 5, 6]
        //
        // Reverse first 2:
        // [2, 1 | 3, 4, 5, 6]
        reverse(nums.begin(), nums.begin() + k);

        // ------------------------------------------------
        // STEP 2: Reverse the remaining elements
        // ------------------------------------------------
        //
        // Current:
        // [2, 1 | 3, 4, 5, 6]
        //
        // Reverse [3, 4, 5, 6]:
        // [2, 1 | 6, 5, 4, 3]
        reverse(nums.begin() + k, nums.end());

        // ------------------------------------------------
        // STEP 3: Reverse the entire array
        // ------------------------------------------------
        //
        // Current:
        // [2, 1 | 6, 5, 4, 3]
        //
        // Reverse everything:
        // [3, 4, 5, 6 | 1, 2]
        //
        // This is our required left rotation.
        reverse(nums.begin(), nums.end());
    }
};

int main()
{

    // Input array.
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Number of positions to rotate.
    int k = 2;

    // Create object of Solution class.
    Solution obj;

    // Perform left rotation.
    obj.rotateArray(nums, k);

    // Print the rotated array.
    cout << "Array after left rotation by " << k << " positions: ";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}