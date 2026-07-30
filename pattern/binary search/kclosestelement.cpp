#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find k closest elements to x
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        //--------------------------------------------------------
        // We are NOT searching for x.
        //
        // We are searching for the starting index of the
        // window of size k.
        //
        // Possible starting indices:
        //
        // If n = 7 and k = 4
        //
        // Window 1 -> starts at 0
        // Window 2 -> starts at 1
        // Window 3 -> starts at 2
        // Window 4 -> starts at 3
        //
        // Therefore:
        //
        // left = 0
        // right = n - k
        //--------------------------------------------------------

        int left = 0;
        int right = arr.size() - k;

        //--------------------------------------------------------
        // Binary Search on window position
        //--------------------------------------------------------

        while (left < right)
        {

            int mid = left + (right - left) / 2;

            //----------------------------------------------------
            // Compare two boundary elements
            //
            // Left boundary  = arr[mid]
            // Right boundary = arr[mid + k]
            //
            // We decide whether the better window lies
            // on the left side or right side.
            //----------------------------------------------------

            if (x - arr[mid] > arr[mid + k] - x)

                // Right boundary is closer to x
                // Shift window right
                left = mid + 1;

            else

                // Left boundary is closer
                // Keep searching left
                right = mid;
        }

        //--------------------------------------------------------
        // left is now the starting index of the answer window.
        //--------------------------------------------------------

        return vector<int>(arr.begin() + left,
                           arr.begin() + left + k);
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5};

    int k = 4;
    int x = 3;

    vector<int> ans = obj.findClosestElements(arr, k, x);

    cout << "The " << k << " closest elements are:\n";

    for (int num : ans)
        cout << num << " ";

    cout << endl;

    return 0;
}