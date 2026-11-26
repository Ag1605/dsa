
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        // Stores the minimum stock price
        // seen so far
        int minprice = prices[0];

        // Stores the maximum profit possible
        int maxprofit = 0;

        // Traverse the prices array
        // Start from index 1 because
        // prices[0] is already our minimum price
        for (int i = 1; i < prices.size(); i++) {

            // Update the minimum price
            // if the current price is smaller
            minprice = min(minprice, prices[i]);

            // Calculate profit if we sell
            // the stock at the current price
            int profit = prices[i] - minprice;

            // Update maximum profit
            // if current profit is greater
            maxprofit = max(profit, maxprofit);
        }

        // Return the maximum profit
        return maxprofit;
    }
};

int main() {

    // Stock prices on different days
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Create Solution object
    Solution obj;

    // Calculate maximum profit
    int result = obj.maxProfit(prices);

    // Print the answer
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
