#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to remove duplicates from a SORTED array.
    //
    // Important:
    // The array must already be sorted.
    //
    // Example:
    // [1, 1, 2, 2, 3]
    //
    // After removing duplicates:
    // [1, 2, 3, _, _]
    //
    // The function returns 3 because there are
    // 3 unique elements.
    int removeDuplicates(vector<int> &nums)
    {

        // 'i' points to the position of the
        // last unique element.
        //
        // Initially, nums[0] is always unique,
        // so i starts at 0.
        int i = 0;

        // 'j' is the second pointer.
        //
        // j scans the entire array looking for
        // new/different elements.
        for (int j = 1; j < nums.size(); j++)
        {

            // If nums[j] is different from nums[i],
            // we have found a new unique element.
            if (nums[i] != nums[j])
            {

                // Move 'i' one position forward.
                //
                // This is the position where the
                // new unique element should be stored.
                i++;

                // Copy the new unique element
                // to position i.
                nums[i] = nums[j];
            }
        }

        // 'i' is an index, not the count.
        //
        // If i = 2:
        // indexes are 0, 1, 2
        // so total unique elements = 3.
        //
        // Therefore return i + 1.
        return i + 1;
    }
};

int main()
{

    // The array must be SORTED.
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    // Create object of Solution class.
    Solution obj;

    // Call the function.
    int k = obj.removeDuplicates(nums);

    // Print number of unique elements.
    cout << "Number of unique elements = " << k << endl;

    // Print the first k elements.
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}