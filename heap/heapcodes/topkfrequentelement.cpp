#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return k most frequent elements
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // Hash Map
        // Key   = Number
        // Value = Frequency
        unordered_map<int, int> mp;

        // Count frequency of every number
        for (int num : nums)
        {
            mp[num]++;
        }

        // ---------------------------------------------------
        // Min Heap
        //
        // pair.first  = Frequency
        // pair.second = Number
        //
        // Smallest frequency remains at the top.
        // If heap size becomes greater than k,
        // remove the smallest frequency.
        // ---------------------------------------------------

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        // Traverse hash map
        for (auto it : mp)
        {

            // Push {frequency, number}
            pq.push({it.second, it.first});

            // Keep only k elements in heap
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Store answer
        vector<int> ans;

        // Extract numbers from heap
        while (!pq.empty())
        {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = 2;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements : ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}