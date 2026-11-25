
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {

        // Stores the sum of elements seen so far
        int sum = 0;

        // Traverse the array from beginning to end
        for (int i = 0; i < nums.size(); i++) {

            // Add the current element to the running sum
            sum = sum + nums[i];

            // Store the running sum at the current index
            nums[i] = sum;
        }

        // Return the modified array
        return nums;
    }
};

int main() {

    // Input array
    vector<int> nums = {1, 2, 3, 4};

    // Create Solution object
    Solution obj;

    // Calculate running sum
    vector<int> result = obj.runningSum(nums);

    // Print the result
    cout << "Running Sum: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
