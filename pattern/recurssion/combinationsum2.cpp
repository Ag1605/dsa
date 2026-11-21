
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Recursive function to generate unique combinations.
    void solve(int index, int target,
               vector<int>& candidates,
               vector<int>& temp,
               vector<vector<int>>& ans)
    {
        // BASE CASE:
        // If target becomes 0, we have found
        // a valid combination.
        if (target == 0)
        {
            // Store the current combination in answer.
            ans.push_back(temp);

            // Return because we have completed this combination.
            return;
        }

        // Try selecting each element starting from index.
        for (int i = index; i < candidates.size(); i++)
        {
            // STEP 1: SKIP DUPLICATES
            //
            // If current element is equal to the previous element
            // at the same recursion level, skip it.
            //
            // This prevents duplicate combinations.
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            // STEP 2: PRUNING
            //
            // Array is sorted.
            // If current element is greater than remaining target,
            // all upcoming elements will also be greater.
            // So stop the loop.
            if (candidates[i] > target)
            {
                break;
            }

            // STEP 3: PICK
            //
            // Select the current element and add it
            // to the current combination.
            temp.push_back(candidates[i]);

            // STEP 4: RECURSION
            //
            // Move to i + 1 because each element
            // can be used only once.
            //
            // Reduce target by the selected element.
            solve(i + 1,
                  target - candidates[i],
                  candidates,
                  temp,
                  ans);

            // STEP 5: BACKTRACK
            //
            // Remove the last selected element.
            // This allows us to explore other combinations.
            temp.pop_back();
        }
    }


    // Main function
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;

        // Stores the current combination.
        vector<int> temp;

        // Sort the array to bring duplicate elements together.
        sort(candidates.begin(), candidates.end());

        // Start recursion from index 0.
        solve(0, target, candidates, temp, ans);

        return ans;
    }
};


int main()
{
    Solution obj;

    // Input array
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    // Required target sum
    int target = 8;

    // Find all unique combinations.
    vector<vector<int>> ans =
        obj.combinationSum2(candidates, target);

    // Print all combinations.
    cout << "Unique Combinations:" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];

            if (j != ans[i].size() - 1)
            {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }

    return 0;
}
