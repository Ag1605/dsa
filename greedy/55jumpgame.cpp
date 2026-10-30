#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check whether we can reach the last index
bool canJump(vector<int>& nums) {

    // Stores the farthest index we can reach so far
    int maxReach = 0;

    // Traverse the array from left to right
    for (int i = 0; i < nums.size(); i++) {

        // If current index is greater than maxReach,
        // it means we cannot reach this index.
        // Therefore, reaching the last index is impossible.
        if (i > maxReach) {
            return false;
        }

        // Calculate how far we can reach from the current index.
        // i + nums[i] = maximum index reachable from current index.
        //
        // Update maxReach only if the new position is farther
        // than our previous maximum reachable position.
        maxReach = max(maxReach, i + nums[i]);

        // If maxReach reaches or crosses the last index,
        // we have successfully reached our destination.
        if (maxReach >= nums.size() - 1) {
            return true;
        }
    }

    // If the loop completes, we can reach the last index.
    return true;
}

int main() {

    // Example input
    vector<int> nums = {2, 3, 1, 1, 4};

    // Call the function
    bool result = canJump(nums);

    // Print the result
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}