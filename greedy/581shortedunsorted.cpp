
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Find the first violation from the left
        // Move left while elements are already in ascending order
        int left = 0;

        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        // If we reach the last index,
        // the entire array is already sorted
        if (left == n - 1) {
            return 0;
        }

        // Step 2: Find the first violation from the right
        // Move right while elements are already in ascending order
        int right = n - 1;

        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        // Step 3: Find the minimum and maximum
        // inside the initially identified unsorted subarray

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = left; i <= right; i++) {

            mini = min(mini, nums[i]);

            maxi = max(maxi, nums[i]);
        }

        // Step 4: Expand the left boundary
        // If an element before left is greater than mini,
        // it also belongs to the unsorted subarray

        while (left > 0 && nums[left - 1] > mini) {
            left--;
        }

        // Step 5: Expand the right boundary
        // If an element after right is smaller than maxi,
        // it also belongs to the unsorted subarray

        while (right < n - 1 && nums[right + 1] < maxi) {
            right++;
        }

        // Step 6: Calculate the length of the subarray
        return right - left + 1;
    }
};

int main() {

    // Given input array
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    // Create Solution object
    Solution obj;

    // Call the function
    int result = obj.findUnsortedSubarray(nums);

    // Print the answer
    cout << "Shortest unsorted subarray length: " << result << endl;

    return 0;
}
