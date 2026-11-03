#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        // Stack stores potential candidates for the 132 pattern
        stack<int> st;

        // Stores the candidate for the middle element (2)
        // Initially, no valid candidate exists
        int second = INT_MIN;

        // Traverse the array from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {

            // STEP 1:
            // Check whether current element can be the first element (1)
            //
            // We already have second representing a candidate for 2
            // If nums[i] < second, then we have:
            //
            // nums[i] < second < some previous larger element (3)
            //
            // Therefore, the 132 pattern exists.

            if (nums[i] < second) {
                return true;
            }

            // STEP 2:
            // Find a suitable middle element (2)
            //
            // If stack top is smaller than current element,
            // current element can act as 3
            // and stack top can act as 2.

            while (!st.empty() && st.top() < nums[i]) {

                // Update second with the popped element
                second = st.top();

                // Remove the element from the stack
                st.pop();
            }

            // STEP 3:
            // Push current element into the stack
            // It may become a candidate for a future 3 or 2.
            st.push(nums[i]);
        }

        // No 132 pattern was found
        return false;
    }
};

int main() {

    Solution obj;

    // Input array
    vector<int> nums = {3, 1, 4, 2};

    // Call the function
    bool result = obj.find132pattern(nums);

    // Print the result
    if (result) {
        cout << "132 Pattern Found" << endl;
    }
    else {
        cout << "132 Pattern Not Found" << endl;
    }

    return 0;
}