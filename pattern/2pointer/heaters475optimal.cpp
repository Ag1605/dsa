#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    // Function returns the minimum radius required
    // to cover every house with at least one heater.
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        // Sort heaters because lower_bound() works on
        // a sorted range.
        //
        // Example:
        // heaters = {4, 1, 10}
        // after sorting:
        // heaters = {1, 4, 10}
        sort(heaters.begin(), heaters.end());

        // 'answer' stores the largest minimum distance
        // found for any house.
        //
        // Why largest?
        // Each house needs to be covered by its closest heater.
        // The house having the largest closest-heater distance
        // determines the required radius.
        int answer = 0;

        // Process every house one by one.
        for (int i = 0; i < houses.size(); i++) {

            // Store the position of the current house.
            int house = houses[i];

            // lower_bound() finds the first heater whose
            // position is >= the current house.
            //
            // Example:
            //
            // heaters = {1, 4, 8, 12}
            // house = 6
            //
            // First heater >= 6 is 8.
            // Therefore:
            // index = 2
            //
            // lower_bound() returns an iterator.
            // Subtracting heaters.begin() converts that
            // iterator into an integer index.
            int index = lower_bound(
                            heaters.begin(),
                            heaters.end(),
                            house
                        ) - heaters.begin();

            // Initially assume there is no heater
            // on either side.
            //
            // INT_MAX is used so that if one side does not
            // exist, the other side's actual distance
            // will automatically become the minimum.
            int leftDistance = INT_MAX;
            int rightDistance = INT_MAX;

            // Check if a heater exists on the RIGHT side.
            //
            // index points to the first heater >= house.
            //
            // Example:
            // heaters = {1, 4, 8, 12}
            // house = 6
            // index = 2
            //
            // heaters[2] = 8
            //
            // Distance = 8 - 6 = 2
            if (index < heaters.size()) {
                rightDistance = heaters[index] - house;
            }

            // Check if a heater exists on the LEFT side.
            //
            // The heater immediately before 'index'
            // is the closest possible heater on the left.
            //
            // Example:
            // heaters = {1, 4, 8, 12}
            // house = 6
            // index = 2
            //
            // heaters[index - 1] = heaters[1] = 4
            //
            // Distance = 6 - 4 = 2
            if (index > 0) {
                leftDistance = house - heaters[index - 1];
            }

            // The closest heater can only be:
            //
            // 1. The first heater >= house (right side)
            // OR
            // 2. The heater immediately before it (left side)
            //
            // So take the smaller distance.
            int closestDistance = min(leftDistance, rightDistance);

            // We need the maximum closest distance among
            // all houses.
            //
            // That maximum distance becomes the required
            // radius to cover every house.
            answer = max(answer, closestDistance);
        }

        // Return the minimum radius needed
        // to cover all houses.
        return answer;
    }
};


int main() {

    // Example input
    vector<int> houses = {1, 2, 3, 4};

    vector<int> heaters = {1, 4};

    // Create an object of Solution class.
    Solution obj;

    // Call findRadius() and store the result.
    int result = obj.findRadius(houses, heaters);

    // Print the answer.
    cout << "Minimum required radius = " << result << endl;

    return 0;
}