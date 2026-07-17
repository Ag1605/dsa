#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        int n = arr.size();

        // Previous Smaller Element index
        vector<int> pse(n);

        // Next Smaller Element index
        vector<int> nse(n);

        // Monotonic increasing stack (stores indices)
        stack<int> st;

        // ---------------- Previous Smaller Element ----------------
        for (int i = 0; i < n; i++)
        {

            // Remove all greater elements
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                pse[i] = -1; // No smaller element on left
            else
                pse[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty())
            st.pop();

        // ---------------- Next Smaller Element ----------------
        for (int i = n - 1; i >= 0; i--)
        {

            // Remove greater or equal elements
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                nse[i] = n; // No smaller element on right
            else
                nse[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        int mod = 1e9 + 7;

        // Contribution of every element
        for (int i = 0; i < n; i++)
        {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            // Contribution = value × left choices × right choices
            ans = (ans + (1LL * arr[i] * left * right) % mod) % mod;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << obj.sumSubarrayMins(arr);

    return 0;
}