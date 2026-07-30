#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return k elements closest to x
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        //----------------------------------------------------------
        // Max Heap
        //
        // pair.first  -> Absolute difference |num - x|
        // pair.second -> Number
        //
        // Why Max Heap?
        // ----------------
        // We want to keep only the k closest elements.
        // The element having the largest difference
        // should remain at the top.
        //
        // If heap size becomes greater than k,
        // remove the farthest element.
        //----------------------------------------------------------

        priority_queue<pair<int, int>> pq;

        //----------------------------------------------------------
        // Traverse every element
        //----------------------------------------------------------

        for (int num : arr)
        {

            // Calculate distance from x
            int diff = abs(num - x);

            // Store {difference, number}
            pq.push({diff, num});

            // Keep only k elements
            if (pq.size() > k)
                pq.pop();
        }

        //----------------------------------------------------------
        // Extract answer
        //----------------------------------------------------------

        vector<int> ans;

        while (!pq.empty())
        {

            ans.push_back(pq.top().second);

            pq.pop();
        }

        //----------------------------------------------------------
        // Problem requires answer in ascending order
        //----------------------------------------------------------

        sort(ans.begin(), ans.end());

        return ans;
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
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}