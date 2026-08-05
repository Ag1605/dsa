#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        // --------------------------------------------------
        // Total number of minutes (shops/customers)
        // --------------------------------------------------
        int n = customers.size();

        // --------------------------------------------------
        // Step 1:
        // Count customers who are already satisfied.
        //
        // If grumpy[i] == 0, the owner is not grumpy,
        // so these customers are always satisfied.
        // --------------------------------------------------
        int base = 0;

        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                base += customers[i];
            }
        }

        // --------------------------------------------------
        // Step 2:
        // Calculate extra satisfied customers in the
        // first window of size "minutes".
        //
        // We only count customers where grumpy == 1
        // because these customers can become satisfied
        // if we use the secret technique.
        // --------------------------------------------------
        int extra = 0;

        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
            {
                extra += customers[i];
            }
        }

        // Initially assume first window is the best.
        int maxExtra = extra;

        // --------------------------------------------------
        // Step 3:
        // Slide the window across the array.
        //
        // Remove left element.
        // Add right element.
        //
        // Update maximum extra customers.
        // --------------------------------------------------
        for (int i = minutes; i < n; i++)
        {
            // Remove left element
            if (grumpy[i - minutes] == 1)
            {
                extra -= customers[i - minutes];
            }

            // Add right element
            if (grumpy[i] == 1)
            {
                extra += customers[i];
            }

            maxExtra = max(maxExtra, extra);
        }

        // --------------------------------------------------
        // Final Answer
        //
        // Already satisfied customers
        // +
        // Maximum extra satisfied customers
        // --------------------------------------------------
        return base + maxExtra;
    }
};

int main()
{
    Solution obj;

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};

    int minutes = 3;

    cout << "Maximum Satisfied Customers = "
         << obj.maxSatisfied(customers, grumpy, minutes);

    return 0;
}