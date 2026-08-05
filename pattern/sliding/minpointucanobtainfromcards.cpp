#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // Total number of cards
        int n = cardPoints.size();

        // ----------------------------------------------------
        // Edge Case:
        // If we have to take all cards, simply return their sum.
        // ----------------------------------------------------
        if (k == n)
        {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        // ----------------------------------------------------
        // Step 1: Find the total sum of all cards.
        //
        // Example:
        // cardPoints = [1,2,3,4,5,6,1]
        // totalSum = 22
        // ----------------------------------------------------
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        // ----------------------------------------------------
        // Step 2:
        // Instead of choosing k cards,
        // think about NOT choosing (n-k) cards.
        //
        // We need the minimum sum subarray of size (n-k).
        //
        // Example:
        // n = 7
        // k = 3
        //
        // windowSize = 7-3 = 4
        // ----------------------------------------------------
        int windowSize = n - k;

        // ----------------------------------------------------
        // Step 3:
        // Calculate the sum of the first window.
        //
        // Example:
        // Window = [1,2,3,4]
        // windowSum = 10
        // ----------------------------------------------------
        int windowSum = 0;

        for (int i = 0; i < windowSize; i++)
        {
            windowSum += cardPoints[i];
        }

        // Assume first window is the minimum.
        int minWindowSum = windowSum;

        // ----------------------------------------------------
        // Step 4:
        // Slide the window one element at a time.
        //
        // Add the new element entering the window.
        // Remove the old element leaving the window.
        //
        // Keep updating the minimum window sum.
        // ----------------------------------------------------
        for (int i = windowSize; i < n; i++)
        {
            // Add new element
            windowSum += cardPoints[i];

            // Remove old element
            windowSum -= cardPoints[i - windowSize];

            // Update minimum window sum
            minWindowSum = min(minWindowSum, windowSum);
        }

        // ----------------------------------------------------
        // Step 5:
        // Maximum score =
        // Total Sum - Minimum Window Sum
        //
        // Because the minimum window represents the cards
        // that we DON'T take.
        // ----------------------------------------------------
        return totalSum - minWindowSum;
    }
};

int main()
{
    Solution obj;

    // Example Input
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Function Call
    cout << "Maximum Score = "
         << obj.maxScore(cardPoints, k);

    return 0;
}