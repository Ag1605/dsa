
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMinSum(vector<int>& a, vector<int>& b) {

        int n = a.size();

        // Step 1: Sort both arrays in ascending order.
        // This helps us pair smaller elements with smaller elements
        // and larger elements with larger elements.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int sum = 0;

        // Step 2: Pair elements at the same index.
        // Calculate the absolute difference between each pair.
        for (int i = 0; i < n; i++) {

            // abs() ensures that the difference is always positive.
            sum += abs(a[i] - b[i]);
        }

        // Step 3: Return the minimum possible sum.
        return sum;
    }
};

int main() {

    // Input arrays.
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};

    Solution obj;

    // Call the function.
    int result = obj.findMinSum(a, b);

    // Print the minimum sum.
    cout << "Minimum sum of absolute differences: "
         << result << endl;

    return 0;
}
