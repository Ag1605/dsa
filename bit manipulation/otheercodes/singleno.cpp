#include <bits/stdc++.h>
using namespace std;

// Function to find the element that appears only once
// Every other element appears exactly twice.
int singleNumber(vector<int> &nums)
{
    // Initially answer is 0
    int ans = 0;

    // Traverse every element of the array
    for (int num : nums)
    {
        // XOR the current element with the answer
        ans ^= num;
    }

    // The remaining value is the unique element
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << singleNumber(nums);

    return 0;
}