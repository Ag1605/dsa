#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the union of two SORTED arrays.
    //
    // Union means:
    // - Take all elements from both arrays
    // - Remove duplicates
    // - Keep the result sorted
    //
    // Example:
    // nums1 = [1, 2, 3, 4]
    // nums2 = [2, 3, 5, 6]
    //
    // Output:
    // [1, 2, 3, 4, 5, 6]
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {

        // i points to the current element of nums1.
        int i = 0;

        // j points to the current element of nums2.
        int j = 0;

        // This vector will store the final union.
        vector<int> ans;

        // Continue while both arrays still have elements.
        while (i < nums1.size() && j < nums2.size())
        {

            // Case 1:
            // nums1[i] is smaller.
            //
            // Therefore, nums1[i] should come next
            // in the sorted union.
            if (nums1[i] < nums2[j])
            {

                // Add nums1[i] only if it is not
                // already the last element of ans.
                //
                // ans.empty() handles the first element.
                if (ans.empty() || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }

                // Move i to the next element of nums1.
                i++;
            }

            // Case 2:
            // nums2[j] is smaller.
            //
            // Therefore, nums2[j] should come next.
            else if (nums2[j] < nums1[i])
            {

                // Add nums2[j] only if it is not
                // already present as the last element.
                if (ans.empty() || ans.back() != nums2[j])
                {
                    ans.push_back(nums2[j]);
                }

                // Move j to the next element of nums2.
                j++;
            }

            // Case 3:
            // nums1[i] == nums2[j]
            //
            // The element exists in both arrays.
            // We only need to add it ONCE.
            else
            {

                // Add the common element once.
                if (ans.empty() || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }

                // Since both elements are equal,
                // move both pointers forward.
                i++;
                j++;
            }
        }

        // nums1 may still contain elements.
        //
        // Add the remaining elements of nums1.
        while (i < nums1.size())
        {

            // Avoid duplicates.
            if (ans.empty() || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }

            i++;
        }

        // nums2 may still contain elements.
        //
        // Add the remaining elements of nums2.
        while (j < nums2.size())
        {

            // Avoid duplicates.
            if (ans.empty() || ans.back() != nums2[j])
            {
                ans.push_back(nums2[j]);
            }

            j++;
        }

        // Return the union.
        return ans;
    }
};

int main()
{

    // Both arrays must be SORTED.
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 3, 5, 5, 6};

    // Create object of Solution class.
    Solution obj;

    // Find union.
    vector<int> ans = obj.unionArray(nums1, nums2);

    // Print result.
    cout << "Union: ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}