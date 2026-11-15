
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        // Track how many $5 and $10 bills we have.
        int five = 0;
        int ten = 0;

        // Process customers one by one.
        for (int i = 0; i < bills.size(); i++) {

            // Case 1: Customer pays $5.
            // No change is required.
            if (bills[i] == 5) {
                five++;
            }

            // Case 2: Customer pays $10.
            // We need to return $5 as change.
            else if (bills[i] == 10) {

                // If we don't have a $5 bill,
                // we cannot provide the change.
                if (five == 0) {
                    return false;
                }

                // Give one $5 bill as change.
                five--;

                // Store the received $10 bill.
                ten++;
            }

            // Case 3: Customer pays $20.
            // We need to return $15 as change.
            else {

                // Greedy choice:
                // First prefer $10 + $5.
                if (ten > 0 && five > 0) {

                    // Give one $10 bill.
                    ten--;

                    // Give one $5 bill.
                    five--;
                }

                // If $10 + $5 is not possible,
                // try giving three $5 bills.
                else if (five >= 3) {

                    // Give three $5 bills.
                    five -= 3;
                }

                // We cannot provide $15 change.
                else {
                    return false;
                }
            }
        }

        // All customers received the correct change.
        return true;
    }
};

int main() {

    // Each element represents the bill paid by a customer.
    vector<int> bills = {5, 5, 5, 10, 20};

    Solution obj;

    bool result = obj.lemonadeChange(bills);

    if (result) {
        cout << "Change can be provided to every customer." << endl;
    }
    else {
        cout << "Change cannot be provided to every customer." << endl;
    }

    return 0;
}
