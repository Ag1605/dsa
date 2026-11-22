
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        // Total number of histogram bars
        int n = heights.size();

        // Stack stores the indices of histogram bars
        stack<int> st;

        // Stores the maximum rectangle area
        int maxi = 0;

        // Traverse all bars.
        // i <= n because we need one extra iteration
        // to process all remaining elements in the stack.
        for (int i = 0; i <= n; i++) {

            // For the last iteration, consider current height as 0.
            // This forces all remaining bars to be popped.
            int currHeight = (i == n) ? 0 : heights[i];

            // If the current bar is smaller than the bar
            // at the top of the stack, we calculate an area.
            while (!st.empty() &&
                   heights[st.top()] > currHeight) {

                // The height of the rectangle is the height
                // of the bar which we are removing.
                int height = heights[st.top()];

                // Remove the index of the current bar.
                st.pop();

                // Previous Smaller Element (PSE).
                // If the stack is empty, no smaller element
                // exists on the left side.
                int pse = -1;

                if (!st.empty()) {
                    pse = st.top();
                }

                // Current index i represents the Next Smaller
                // Element (NSE).

                // Calculate the maximum possible width.
                int width = i - pse - 1;

                // Calculate the rectangle area.
                int area = height * width;

                // Update maximum area.
                maxi = max(maxi, area);
            }

            // Push the current index into the stack.
            st.push(i);
        }

        // Return the maximum rectangle area.
        return maxi;
    }
};

int main() {

    // Given histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Create Solution object
    Solution obj;

    // Calculate the largest rectangle area
    int ans = obj.largestRectangleArea(heights);

    // Print the answer
    cout << "Largest Rectangle Area: " << ans << endl;

    return 0;
}
