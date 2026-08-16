#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        // diff[x] stores the CHANGE in number of passengers
        // at location x.
        //
        // +passengers -> passengers get INTO the car
        // -passengers -> passengers get OUT of the car
        //
        // Since the maximum location in this problem is 1000,
        // we can use an array of size 1001.
        vector<int> diff(1001, 0);

        // =========================================================
        // STEP 1: STORE PASSENGER CHANGES
        // =========================================================
        //
        // Each trip is:
        //
        // trips[i] = {passengers, from, to}
        //
        // Example:
        //
        // {2, 1, 5}
        //
        // Means:
        // 2 passengers enter at location 1
        // 2 passengers leave at location 5
        //
        for (int i = 0; i < trips.size(); i++)
        {

            int passengers = trips[i][0];

            int from = trips[i][1];

            int to = trips[i][2];

            // At 'from', passengers enter the car.
            // Therefore increase the passenger count.
            diff[from] += passengers;

            // At 'to', passengers leave the car.
            // Therefore decrease the passenger count.
            diff[to] -= passengers;
        }

        // =========================================================
        // STEP 2: SWEEP THROUGH ALL LOCATIONS
        // =========================================================
        //
        // current = number of passengers currently inside the car.
        int current = 0;

        // Go from location 0 to 1000.
        for (int i = 0; i <= 1000; i++)
        {

            // Apply the passenger change at this location.
            current += diff[i];

            // If current passengers are greater than
            // the car's capacity, the trip is impossible.
            if (current > capacity)
            {
                return false;
            }
        }

        // At no point did we exceed capacity.
        return true;
    }
};

int main()
{

    Solution solution;

    // =========================================================
    // TEST CASE 1
    // =========================================================

    vector<vector<int>> trips1 = {
        {2, 1, 5},
        {3, 3, 7}};

    int capacity1 = 4;

    cout << boolalpha;

    cout << solution.carPooling(trips1, capacity1) << endl;

    // Explanation:
    //
    // Trip 1:
    // 2 passengers from 1 -> 5
    //
    // Trip 2:
    // 3 passengers from 3 -> 7
    //
    // From 1 to 3:
    // 2 passengers
    //
    // From 3 to 5:
    // 2 + 3 = 5 passengers
    //
    // Capacity = 4
    //
    // 5 > 4
    //
    // Therefore:
    // false

    // =========================================================
    // TEST CASE 2
    // =========================================================

    vector<vector<int>> trips2 = {
        {2, 1, 5},
        {3, 5, 7}};

    int capacity2 = 3;

    cout << solution.carPooling(trips2, capacity2) << endl;

    // Explanation:
    //
    // Trip 1:
    // 2 passengers from 1 -> 5
    //
    // At location 5, those 2 passengers leave.
    //
    // At the same location 5,
    // 3 new passengers enter.
    //
    // So we never have more than 3 passengers.
    //
    // Therefore:
    // true

    return 0;
}