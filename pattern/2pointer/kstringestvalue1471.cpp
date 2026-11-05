
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        // Step 1: Sort the array in ascending order
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Step 2: Find the median
        // For even-sized arrays, use the smaller middle element
        int m = arr[(n - 1) / 2];

        // Step 3: Initialize two pointers
        // left points to the smallest element
        // right points to the largest element
        int left = 0;
        int right = n - 1;

        // Store the k strongest elements
        vector<int> ans;

        // Step 4: Select k strongest elements
        for (int i = 0; i < k; i++) {

            // Calculate distance of left element from median
            int leftDist = abs(arr[left] - m);

            // Calculate distance of right element from median
            int rightDist = abs(arr[right] - m);

            // Step 5: Compare the strengths
            if (leftDist > rightDist) {

                // Left element is stronger
                ans.push_back(arr[left]);

                // Move left pointer forward
                left++;
            }
            else {

                // Right element is stronger
                // If distances are equal, right element wins
                // because it is greater than the left element
                ans.push_back(arr[right]);

                // Move right pointer backward
                right--;
            }
        }

        // Step 6: Return k strongest elements
        return ans;
    }
};

int main() {

    // Given input array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Number of strongest elements required
    int k = 2;

    // Create Solution object
    Solution obj;

    // Call the function
    vector<int> result = obj.getStrongest(arr, k);

    // Print the result
    cout << "K Strongest Elements: ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
