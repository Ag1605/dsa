#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        // --------------------------------------------------
        // white -> Number of white blocks ('W')
        // inside the current window.
        // --------------------------------------------------
        int white = 0;

        // --------------------------------------------------
        // Step 1:
        // Count white blocks in the first window of size k.
        //
        // Example:
        // blocks = "WBBWWBBWBW"
        // k = 7
        //
        // First Window:
        // W B B W W B B
        //
        // White Count = 3
        // --------------------------------------------------
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
            {
                white++;
            }
        }

        // --------------------------------------------------
        // Initially assume the first window gives
        // the minimum recolors required.
        // --------------------------------------------------
        int ans = white;

        // --------------------------------------------------
        // Step 2:
        // Slide the window one position at a time.
        //
        // Add the new character entering the window.
        // Remove the old character leaving the window.
        //
        // Keep track of the minimum number of whites.
        // --------------------------------------------------
        for (int i = k; i < blocks.size(); i++)
        {
            // New character enters the window.
            if (blocks[i] == 'W')
            {
                white++;
            }

            // Old character leaves the window.
            if (blocks[i - k] == 'W')
            {
                white--;
            }

            // Minimum whites seen so far.
            ans = min(ans, white);
        }

        // --------------------------------------------------
        // Minimum white blocks =
        // Minimum recolors needed.
        // --------------------------------------------------
        return ans;
    }
};

int main()
{
    Solution obj;

    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout << "Minimum Recolors = "
         << obj.minimumRecolors(blocks, k);

    return 0;
}