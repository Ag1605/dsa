#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();

    // Step 1: Calculate first window sum
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];      // add next element
        windowSum -= arr[i - k];  // remove previous element

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}



class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;

        int low = 0, high = 0;
        int sum = 0, maxsum = 0;

        while (high < n) {
            sum += arr[high];  // expand window

            // when window size becomes k
            if (high - low + 1 == k) {
                maxsum = max(maxsum, sum);

                sum -= arr[low]; // remove left element
                low++;           // shrink window
            }

            high++; // always move forward
        }

        return maxsum;
    }
};

int main() {
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    cout << maxSumSubarray(arr, k);

    return 0;
}