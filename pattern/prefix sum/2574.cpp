
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:

    vector<int> leftRightDifference(vector<int>& nums) {

        // Get the size of the array
        int n = nums.size();

        // Calculate the total sum of the array
        int totalSum = 0;

        // Traverse the array to calculate total sum
        for (int i = 0; i < n; i++) {

            // Add the current element to total sum
            totalSum += nums[i];
        }

        // Stores the sum of elements on the left
        // Initially, there are no elements on the left
        int leftSum = 0;

        // Stores the final answer
        vector<int> ans(n);

        // Calculate left and right sum for every index
        for (int i = 0; i < n; i++) {

            // Right sum excludes the current element
            //
            // Total Sum =
            // Left Sum + Current Element + Right Sum
            //
            // Therefore:
            // Right Sum = Total Sum - Left Sum - Current Element
            int rightSum = totalSum - leftSum - nums[i];

            // Store the absolute difference
            ans[i] = abs(leftSum - rightSum);

            // Add current element to left sum
            // for the next index
            leftSum += nums[i];
        }

        // Return the answer array
        return ans;
    }
};

int main() {

    // Input array
    vector<int> nums = {10, 4, 8, 3};

    // Create Solution object
    Solution obj;

    // Calculate left-right differences
    vector<int> result = obj.leftRightDifference(nums);

    // Print the result
    cout << "Left Right Difference: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
