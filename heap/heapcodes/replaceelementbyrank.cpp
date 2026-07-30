#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to replace every element with its rank
    vector<int> replaceWithRank(vector<int> &arr)
    {

        //---------------------------------------------------------
        // Step 1: Make a copy of the original array.
        // We will sort this copy while keeping the original array
        // unchanged.
        //---------------------------------------------------------

        vector<int> temp = arr;

        //---------------------------------------------------------
        // Step 2: Sort the copied array.
        //---------------------------------------------------------

        sort(temp.begin(), temp.end());

        //---------------------------------------------------------
        // Step 3: Store the rank of every unique number.
        //
        // Key   -> Number
        // Value -> Rank
        //---------------------------------------------------------

        unordered_map<int, int> rank;

        // Rank starts from 1
        int r = 1;

        //---------------------------------------------------------
        // Step 4: Traverse the sorted array.
        //
        // If the number has not been assigned a rank,
        // assign the current rank.
        //---------------------------------------------------------

        for (int num : temp)
        {

            // Assign rank only once for every unique number
            if (rank.find(num) == rank.end())
            {

                rank[num] = r;

                r++;
            }
        }

        //---------------------------------------------------------
        // Step 5: Replace every element of the original array
        // with its corresponding rank.
        //---------------------------------------------------------

        vector<int> ans;

        for (int num : arr)
        {

            ans.push_back(rank[num]);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {20, 15, 26, 2, 98, 6};

    vector<int> ans = obj.replaceWithRank(arr);

    cout << "Original Array:\n";

    for (int num : arr)
        cout << num << " ";

    cout << "\n\nArray After Replacing With Rank:\n";

    for (int num : ans)
        cout << num << " ";

    cout << endl;

    return 0;
}