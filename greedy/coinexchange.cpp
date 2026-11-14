
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // Step 1: Sort coins in descending order.
        // We try to use the largest denomination first.
        sort(coins.begin(), coins.end(), greater<int>());

        int count = 0;

        // Step 2: Traverse all coin denominations.
        for (int i = 0; i < coins.size(); i++) {

            // Check if the current coin can be used.
            if (amount >= coins[i]) {

                // Take as many coins of this denomination as possible.
                count += amount / coins[i];

                // Calculate the remaining amount.
                amount = amount % coins[i];
            }
        }

        // Step 3: Check whether the complete amount was formed.
        if (amount == 0) {
            return count;
        }

        // Amount cannot be formed using the selected coins.
        return -1;
    }
};

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;

    int result = obj.coinChange(coins, amount);

    cout << "Minimum number of coins: " << result << endl;

    return 0;
}
