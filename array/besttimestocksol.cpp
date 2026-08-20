#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum profit
    // that can be made by buying and selling a stock.
    int maxProfit(vector<int> &prices)
    {

        // Store the minimum price seen so far.
        // Initially, the first day's price is the minimum.
        int minprice = prices[0];

        // Store the maximum profit found so far.
        // Initially, we have made no profit.
        int maxprofit = 0;

        // Start from the second day because
        // the first day's price is already stored in minprice.
        for (int i = 1; i < prices.size(); i++)
        {

            // Update the minimum buying price.
            //
            // If today's price is smaller than minprice,
            // today's price becomes the new best price to buy.
            minprice = min(minprice, prices[i]);

            // Calculate the profit if we sell the stock today.
            //
            // Selling price = prices[i]
            // Buying price  = minprice
            //
            // Profit = Selling Price - Buying Price
            int profit = prices[i] - minprice;

            // Update maximum profit if today's profit
            // is greater than the maximum profit found so far.
            maxprofit = max(maxprofit, profit);
        }

        // Return the maximum profit possible.
        return maxprofit;
    }
};

int main()
{

    // Example input:
    // Buy at 1 and sell at 6
    // Maximum profit = 6 - 1 = 5
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Create an object of Solution class.
    Solution obj;

    // Call maxProfit() to calculate the answer.
    int answer = obj.maxProfit(prices);

    // Print the maximum profit.
    cout << "Maximum Profit = " << answer << endl;

    return 0;
}