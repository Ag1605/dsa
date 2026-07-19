#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        // Deque stores indices
        // Elements in deque are always in decreasing order of values
        deque<int> dq;

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {

            // Remove indices that are outside the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all smaller elements from the back
            // because they can never become the maximum
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Insert current index
            dq.push_back(i);

            // First window is formed when i >= k-1
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}