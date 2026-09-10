#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode 219: Contains Duplicate II

    We need to find whether the array contains
    two equal values whose indices are at most
    k positions apart.

    Example:
        nums = [1,2,3,1]
        k = 3

        1 is at index 0
        1 is at index 3

        Distance = 3 - 0 = 3

        3 <= k
        3 <= 3

        Answer = true


    APPROACH:
    Sliding Window + unordered_set

    We maintain a window containing the previous
    k elements.

    If the current element is already present
    in the window, we found a nearby duplicate.
*/

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    /*
        If k = 0, two different indices can never
        have a distance <= 0.

        Therefore, immediately return false.
    */
    if (k == 0)
    {
        return false;
    }


    /*
        unordered_set stores unique values.

        This set represents our current sliding window.

        Example:

        k = 3

        window could contain:

        {5, 6, 7}

        These are the previous elements
        that are close enough to the current index.
    */
    unordered_set<int> window;


    /*
        Traverse the array from left to right.

        i = current index
    */
    for (int i = 0; i < nums.size(); i++)
    {
        /*
            Check whether the current number is
            already present in the window.

            window.count(x):

                returns 1 -> x exists
                returns 0 -> x does not exist

            If it exists, then we have found
            a duplicate within distance k.
        */
        if (window.count(nums[i]))
        {
            return true;
        }


        /*
            Current number is not in the window.

            So add it to the window.
        */
        window.insert(nums[i]);


        /*
            If i >= k, our window has become
            larger than k elements.

            We need to remove the element that
            is now too far away.

            The element to remove is:

                nums[i - k]

            Example:

                i = 3
                k = 3

                i - k = 0

                So we remove nums[0].
        */
        if (i >= k)
        {
            window.erase(nums[i - k]);
        }
    }


    /*
        We checked the complete array and did not
        find any nearby duplicate.

        Therefore, return false.
    */
    return false;
}


int main()
{
    /*
        Test input

        Array:
        [1,2,3,4,5,6,7,8,9,10,9]

        k = 3
    */
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9};

    int k = 3;


    /*
        Call the function.
    */
    bool result = containsNearbyDuplicate(nums, k);


    /*
        Print the result.
    */
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }


    return 0;
}