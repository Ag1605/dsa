#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the missing number.
    //
    // The array contains n distinct numbers
    // taken from the range [0, n].
    //
    // Example:
    // nums = [3, 0, 1]
    //
    // n = 3
    // Expected numbers = [0, 1, 2, 3]
    // Missing number = 2
    int missingNumber(vector<int> &nums)
    {

        // The size of the array is n.
        //
        // Example:
        // nums = [3, 0, 1]
        // n = 3
        int n = nums.size();

        // Calculate the expected sum of all numbers
        // from 0 to n.
        //
        // Formula:
        //
        // n * (n + 1) / 2
        //
        // Example:
        // n = 3
        //
        // 3 * 4 / 2 = 6
        //
        // Expected:
        // 0 + 1 + 2 + 3 = 6
        int expected = n * (n + 1) / 2;

        // Calculate the actual sum of the elements
        // present in the array.
        //
        // accumulate() adds all elements:
        //
        // nums = [3, 0, 1]
        // actual = 3 + 0 + 1 = 4
        //
        // The third argument 0 is the initial value.
        int actual = accumulate(nums.begin(), nums.end(), 0);

        // The missing number is:
        //
        // Expected sum - Actual sum
        //
        // 6 - 4 = 2
        return expected - actual;
    }
};

int main()
{

    // Create the input array.
    vector<int> nums = {3, 0, 1};

    // Create an object of Solution class.
    Solution obj;

    // Call the missingNumber() function.
    int answer = obj.missingNumber(nums);

    // Print the missing number.
    cout << "Missing number = " << answer << endl;

    return 0;
}