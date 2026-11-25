
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:

    // Stores cumulative sums
    vector<int> prefix;

public:

    // Constructor: builds the prefix sum array
    NumArray(vector<int>& nums) {

        // Get the size of the input array
        int n = nums.size();

        // Create prefix array of size n + 1
        // The first element is 0
        prefix.resize(n + 1, 0);

        // Calculate prefix sums
        for (int i = 0; i < n; i++) {

            // prefix[i] contains the sum
            // of elements before index i
            //
            // Add nums[i] to get the sum
            // up to the current element
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    // Returns the sum from left to right
    int sumRange(int left, int right) {

        // prefix[right + 1] contains the sum
        // from index 0 to right
        //
        // prefix[left] contains the sum
        // before index left
        //
        // Subtracting removes the unwanted
        // elements before left
        return prefix[right + 1] - prefix[left];
    }
};

int main() {

    // Input array
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    // Create NumArray object
    // Constructor builds the prefix sum array
    NumArray obj(nums);

    // Perform range sum queries
    cout << "Sum from index 0 to 2: ";
    cout << obj.sumRange(0, 2) << endl;

    cout << "Sum from index 2 to 5: ";
    cout << obj.sumRange(2, 5) << endl;

    cout << "Sum from index 0 to 5: ";
    cout << obj.sumRange(0, 5) << endl;

    return 0;
}
