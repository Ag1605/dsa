#include <bits/stdc++.h>
using namespace std;

// Function to find the two unique numbers
vector<int> singleNumber(vector<int> &nums)
{
    // XOR of all elements
    int xr = 0;

    for (int num : nums)
    {
        xr ^= num;
    }

    // Find the rightmost set bit.
    // This bit is different in the two unique numbers.
    int rightMost = xr & (-xr);

    // These variables will store the two unique numbers
    int first = 0;
    int second = 0;

    // Divide the numbers into two groups
    for (int num : nums)
    {
        // Group 1:
        // Numbers having the rightMost bit set
        if (num & rightMost)
            first ^= num;

        // Group 2:
        // Numbers not having the rightMost bit set
        else
            second ^= num;
    }

    // Return answers in increasing order
    if (first > second)
        swap(first, second);

    return {first, second};
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = singleNumber(nums);

    cout << ans[0] << " " << ans[1];

    return 0;
}