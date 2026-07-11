#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates,
               vector<vector<int>> &ans,
               vector<int> &current,
               int target,
               int index)
    {
        // Base Case 1:
        // Target becomes 0, we found a valid combination
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }

        // Base Case 2:
        // No more elements left
        if (index == candidates.size())
            return;

        // Choice 1: Take the current element
        // We can take it only if it does not exceed the target
        if (candidates[index] <= target)
        {

            current.push_back(candidates[index]); // Choose

            // Explore
            // Same index because the current element
            // can be used unlimited times
            solve(candidates,
                  ans,
                  current,
                  target - candidates[index],
                  index);

            current.pop_back(); // Undo (Backtrack)
        }

        // Choice 2: Skip the current element
        solve(candidates,
              ans,
              current,
              target,
              index + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates,
                                       int target)
    {

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates,
              ans,
              current,
              target,
              0);

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cin >> n;

    vector<int> candidates(n);

    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> ans = obj.combinationSum(candidates, target);

    for (auto combination : ans)
    {

        cout << "[ ";

        for (int num : combination)
            cout << num << " ";

        cout << "]" << endl;
    }

    return 0;
}