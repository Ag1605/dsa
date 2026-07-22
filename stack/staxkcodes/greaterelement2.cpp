#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Initialize answer array with -1
        vector<int> ans(n, -1);

        // Monotonic decreasing stack
        stack<int> st;

        // Traverse the array twice from right to left
        // to simulate a circular array
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Circular index
            int index = i % n;

            // Remove all elements smaller than or equal to current element
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // During the second pass (i < n),
            // assign the next greater element
            if (i < n) {
                if (!st.empty())
                    ans[index] = st.top();
            }

            // Push current element into stack
            st.push(nums[index]);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = obj.nextGreaterElements(nums);

    for (int x : ans)
        cout << x << " ";

    return 0;
}