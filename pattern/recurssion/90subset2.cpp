
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Stores all unique subsets
    vector<vector<int>> ans;

    // Stores the subset currently being generated
    vector<int> subset;


    // Backtracking function
    // start tells us the index from where we can pick elements
    void backtrack(vector<int>& nums, int start)
    {
        // STEP 1: Add the current subset to the answer
        //
        // Every subset is a valid answer, including the empty subset.
        // We add the current subset before making further choices.
        ans.push_back(subset);


        // STEP 2: Try picking elements one by one
        //
        // We start from 'start' because we don't want to reuse
        // previous elements or generate different orderings.
        for (int i = start; i < nums.size(); i++)
        {
            // STEP 3: Skip duplicate elements at the same level
            //
            // If the current element is equal to the previous element,
            // skip it when both are at the same recursion level.
            //
            // This prevents generating duplicate subsets.
            //
            // Example:
            // nums = [1, 2, 2]
            //
            // We skip the second 2 when exploring the same level,
            // but we can still select both 2s in a deeper recursion.
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }


            // STEP 4: Choose the current element
            //
            // Add nums[i] to our current subset.
            subset.push_back(nums[i]);


            // STEP 5: Explore further possibilities
            //
            // Call backtrack with i + 1 because:
            // We can only select elements appearing after i.
            // This ensures each element is used at most once.
            backtrack(nums, i + 1);


            // STEP 6: Undo the choice (Backtracking)
            //
            // Remove the last inserted element.
            // This allows us to explore other possible subsets
            // without keeping the previous choice.
            subset.pop_back();
        }
    }


    // Main function called by LeetCode
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        // STEP 1: Sort the array
        //
        // Sorting brings duplicate elements together.
        // This makes it easy to identify and skip duplicates.
        sort(nums.begin(), nums.end());


        // STEP 2: Start backtracking from index 0
        backtrack(nums, 0);


        // STEP 3: Return all unique subsets
        return ans;
    }
};


int main()
{
    Solution obj;

    // Input array containing duplicate elements
    vector<int> nums = {1, 2, 2};

    // Generate all unique subsets
    vector<vector<int>> result = obj.subsetsWithDup(nums);


    // Print all subsets
    cout << "All unique subsets are:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << "{ ";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}
