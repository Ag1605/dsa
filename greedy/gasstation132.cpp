#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // total = keeps track of the total gas gained/lost
        // over the complete journey.
        int total = 0;

        // tank = gas currently available in the car
        // while trying to start from 'start'.
        int tank = 0;

        // start = index of the station from where
        // we are currently assuming the journey can start.
        int start = 0;

        // Check every gas station one by one.
        for (int i = 0; i < gas.size(); i++) {

            // Difference tells us how much gas we gain
            // or lose at the current station.
            //
            // Example:
            // gas[i] = 5
            // cost[i] = 3
            // diff = 2
            // We gain 2 units of gas.
            int diff = gas[i] - cost[i];

            // Add the difference to total.
            // This tells us whether there is enough gas
            // to complete the entire circular journey.
            total += diff;

            // Add the difference to our current tank.
            tank += diff;

            // If tank becomes negative, it means:
            // Starting from 'start', we cannot even reach
            // the next station.
            if (tank < 0) {

                // Therefore, none of the stations from
                // start to i can be a valid starting point.
                //
                // So we try the next station.
                start = i + 1;

                // Reset the tank because we are starting
                // a new attempt from start.
                tank = 0;
            }
        }

        // If total gas is less than total cost,
        // completing the circular journey is impossible.
        if (total < 0)
            return -1;

        // Otherwise, 'start' is the valid starting station.
        return start;
    }
};

int main() {

    // Example input
    vector<int> gas = {1, 2, 3, 4, 5};

    vector<int> cost = {3, 4, 5, 1, 2};

    // Create an object of Solution class.
    Solution obj;

    // Call the function.
    int answer = obj.canCompleteCircuit(gas, cost);

    // Print the answer.
    cout << "Starting Gas Station Index: " << answer << endl;

    return 0;
}