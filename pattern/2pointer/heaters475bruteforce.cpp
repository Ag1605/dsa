#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:

    // This function finds the minimum radius required
    // so that every house is covered by at least one heater.
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        // 'ans' stores the maximum of all minimum distances.
        //
        // Why maximum?
        // For every house, we find its CLOSEST heater.
        // The farthest house from its closest heater
        // determines the minimum required radius.
        int ans = 0;

        // Go through every house one by one.
        for (int i = 0; i < houses.size(); i++) {

            // For the current house, initially assume
            // the minimum distance is very large.
            int mindist = INT_MAX;

            // Check the distance from the current house
            // to every heater.
            for (int j = 0; j < heaters.size(); j++) {

                // Calculate absolute distance between
                // current house and current heater.
                //
                // Example:
                // house = 2, heater = 7
                // distance = |2 - 7| = 5
                int dist = abs(houses[i] - heaters[j]);

                // If this heater is closer to the house
                // than the previous closest heater,
                // update mindist.
                if (dist < mindist) {
                    mindist = dist;
                }
            }

            // 'mindist' is the distance from this house
            // to its closest heater.
            //
            // We need the largest such distance because
            // that house requires the biggest radius.
            if (mindist > ans) {
                ans = mindist;
            }
        }

        // 'ans' is the minimum radius needed
        // to cover all houses.
        return ans;
    }
};


int main() {

    // Example input
    vector<int> houses = {1, 2, 3, 4};
    vector<int> heaters = {1, 4};

    // Create Solution object
    Solution obj;

    // Call findRadius()
    int result = obj.findRadius(houses, heaters);

    // Print the answer
    cout << "Minimum required radius = " << result << endl;

    return 0;
}