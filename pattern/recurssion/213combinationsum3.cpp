
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Stores all valid combinations
    vector<vector<int>> ans;

    // Stores the current combination
    vector<int> path;


    // Backtracking function
    //
    // start = number from which we can start choosing
    // k     = required number of elements
    // n     = target sum
    // sum   = current sum of selected elements
    void back(int start, int k, int n, int sum)
    {
        // STEP 1: Base Case
        //
        // We need exactly k numbers in our combination.
        if (path.size() == k)
        {
            // If exactly k numbers are selected
            // and their sum equals n, it is a valid combination.
            if (sum == n)
            {
                ans.push_back(path);
            }

            // Stop exploring this path.
            return;
        }


        // STEP 2: Try choosing numbers from start to 9
        //
        // We only use numbers from 1 to 9.
        for (int i = start; i <= 9; i++)
        {
            // STEP 3: Pruning
            //
            // If adding the current number makes the sum
            // greater than n, we stop exploring.
            //
            // Since numbers are increasing, all upcoming
            // numbers will also make the sum larger.
            if (sum + i > n)
            {
                break;
            }


            // STEP 4: Choose
            //
            // Add the current number to our combination.
            path.push_back(i);


            // STEP 5: Explore
            //
            // Move to i + 1 because:
            // 1. Numbers cannot be repeated.
            // 2. Combinations must be in increasing order.
            //
            // Update the current sum by adding i.
            back(i + 1, k, n, sum + i);


            // STEP 6: Backtrack
            //
            // Remove the last selected number.
            // Now we can try another number.
            path.pop_back();
        }
    }


    // Main function called by LeetCode
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // Start selecting numbers from 1.
        // Initially, the current sum is 0.
        back(1, k, n, 0);

        return ans;
    }
};


int main()
{
    Solution obj;

    int k = 3;
    int n = 7;

    // Generate all valid combinations
    vector<vector<int>> result = obj.combinationSum3(k, n);


    // Print the result
    cout << "Valid combinations:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
