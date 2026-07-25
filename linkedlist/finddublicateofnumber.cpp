#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        // Slow and Fast pointers start from index 0
        int slow = 0;
        int fast = 0;

        while (true)
        {

            // Slow moves one step
            slow = nums[slow];

            // Fast moves two steps
            fast = nums[fast];
            fast = nums[fast];

            // Cycle detected
            if (slow == fast)
            {

                // Move slow back to the beginning
                slow = 0;

                // Move both one step at a time
                while (slow != fast)
                {
                    slow = nums[slow];
                    fast = nums[fast];
                }

                // Duplicate number
                return slow;
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << obj.findDuplicate(nums);

    return 0;
}