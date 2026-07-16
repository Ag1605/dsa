#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int n = temperatures.size();

        // Initialize answer array with 0
        // If no warmer day exists, answer remains 0
        vector<int> ans(n, 0);

        // Monotonic stack stores indices of temperatures
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {

            // Remove all temperatures that are
            // smaller than or equal to the current temperature
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            // If stack is not empty,
            // top contains the next warmer day's index
            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }

            // Store current day's index
            st.push(i);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> temperatures(n);

    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }

    vector<int> ans = obj.dailyTemperatures(temperatures);

    for (int x : ans)
        cout << x << " ";

    return 0;
}