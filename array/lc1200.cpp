
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        int n = arr.size();

        // Step 1: Sort the array in ascending order.
        // After sorting, the closest elements will be adjacent.
        sort(arr.begin(), arr.end());

        // Step 2: Find the minimum absolute difference.
        int mini = INT_MAX;

        // Compare every element with its previous element.
        for (int i = 1; i < n; i++) {

            // Since the array is sorted, subtraction
            // will always give a non-negative difference.
            int diff = arr[i] - arr[i - 1];

            // Update minimum difference if a smaller one is found.
            mini = min(mini, diff);
        }

        // Step 3: Store all pairs having minimum difference.
        vector<vector<int>> ans;

        // Traverse the sorted array again.
        for (int i = 1; i < n; i++) {

            // Check whether the adjacent elements
            // have the minimum difference.
            if (arr[i] - arr[i - 1] == mini) {

                // Store the pair in ascending order.
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        // Step 4: Return all pairs.
        return ans;
    }
};

int main() {

    // Given input array.
    vector<int> arr = {4, 2, 1, 3};

    Solution obj;

    // Call the function.
    vector<vector<int>> result = obj.minimumAbsDifference(arr);

    // Print all pairs having minimum absolute difference.
    cout << "Pairs with minimum absolute difference:" << endl;

    for (int i = 0; i < result.size(); i++) {

        cout << "[" << result[i][0]
             << ", " << result[i][1] << "]" << endl;
    }

    return 0;
}
