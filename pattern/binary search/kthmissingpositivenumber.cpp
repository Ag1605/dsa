#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        // Find the first index where
        // missing numbers >= k
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Number of missing positive integers
            // before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // Need to search on the right
                low = mid + 1;
            }
            else {
                // Possible answer is on the left
                high = mid - 1;
            }
        }

        // 'high' = number of elements before the answer
        // 'low'  = position where missing count becomes >= k
        //
        // Answer = k missing numbers + 'high' elements
        return low + k;
    }
};

int main() {

    Solution sol;

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << sol.findKthPositive(arr, k);

    return 0;
}