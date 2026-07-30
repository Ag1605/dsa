#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return indices of k weakest rows
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        // Max Heap
        // pair = {number of soldiers, row index}
        //
        // Why Max Heap?
        // ----------------
        // We only want to keep k weakest rows.
        // If heap size becomes greater than k,
        // remove the strongest row (largest soldiers).
        priority_queue<pair<int, int>> pq;

        // Traverse every row
        for (int i = 0; i < mat.size(); i++)
        {

            // Count soldiers in current row
            int soldiers = 0;

            // Traverse all columns of current row
            for (int j = 0; j < mat[i].size(); j++)
            {
                soldiers += mat[i][j];
            }

            // Insert {soldiers, row index}
            pq.push({soldiers, i});

            // Keep heap size only k
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Store answer
        vector<int> ans;

        // Extract row indices
        while (!pq.empty())
        {

            // second = row index
            ans.push_back(pq.top().second);

            pq.pop();
        }

        // Since max heap gives strongest among stored rows first,
        // reverse to get weakest -> strongest
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    // Matrix
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0}, // 2 soldiers
        {1, 1, 1, 1, 0}, // 4 soldiers
        {1, 0, 0, 0, 0}, // 1 soldier
        {1, 1, 0, 0, 0}, // 2 soldiers
        {1, 1, 1, 1, 1}  // 5 soldiers
    };

    int k = 3;

    vector<int> ans = obj.kWeakestRows(mat, k);

    cout << "The " << k << " weakest rows are:\n";

    for (int index : ans)
    {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}