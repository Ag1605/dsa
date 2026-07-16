#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        stack<int> st;

        // Stores: element -> next greater element
        unordered_map<int, int> mp;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--)
        {

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            // Store next greater element
            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            // Push current element
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Find answers for nums1 using the map
        for (int x : nums1)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    int n1, n2;

    cin >> n1;

    vector<int> nums1(n1);

    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    cin >> n2;

    vector<int> nums2(n2);

    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    for (int x : ans)
        cout << x << " ";

    return 0;
}