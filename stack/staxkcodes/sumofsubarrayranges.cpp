#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {

        int n = nums.size();

        // Previous Smaller Element
        vector<int> pse(n);

        // Next Smaller Element
        vector<int> nse(n);

        // Previous Greater Element
        vector<int> pge(n);

        // Next Greater Element
        vector<int> nge(n);

        // Monotonic stack (stores indices)
        stack<int> st;

        // ---------------- Previous Smaller ----------------
        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- Next Smaller ----------------
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- Previous Greater ----------------
        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- Next Greater ----------------
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        // Contribution of every element
        for (int i = 0; i < n; i++)
        {

            // Contribution as Minimum
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            minSum += 1LL * nums[i] * leftMin * rightMin;

            // Contribution as Maximum
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        // Sum of ranges = Sum of Maximums - Sum of Minimums
        return maxSum - minSum;
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

    cout << obj.subArrayRanges(nums);

    return 0;
}