#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        // Stack stores indices of bars
        stack<int> st;

        int water = 0;

        // Traverse all bars
        for (int i = 0; i < height.size(); i++)
        {

            // If current bar is taller than the top of stack,
            // water can be trapped.
            while (!st.empty() && height[i] > height[st.top()])
            {

                // Bottom of the container
                int middle = st.top();
                st.pop();

                // No left boundary
                if (st.empty())
                {
                    break;
                }

                // Left boundary
                int left = st.top();

                // Distance between left and right walls
                int width = i - left - 1;

                // Water height above the middle bar
                int h = min(height[left], height[i]) - height[middle];

                // Water trapped in this container
                water += width * h;
            }

            // Push current index
            st.push(i);
        }

        return water;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++)
        cin >> height[i];

    cout << obj.trap(height);

    return 0;
}