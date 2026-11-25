
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int largestAltitude(vector<int>& gain) {

        // Stores the current altitude
        int sum = 0;

        // Stores the highest altitude reached
        // Initially 0 because the biker starts
        // at altitude 0
        int maxAltitude = 0;

        // Traverse the gain array
        for (int i = 0; i < gain.size(); i++) {

            // Update the current altitude
            sum = sum + gain[i];

            // Update the maximum altitude
            if (sum > maxAltitude) {
                maxAltitude = sum;
            }
        }

        // Return the highest altitude
        return maxAltitude;
    }
};

int main() {

    // Input array
    vector<int> gain = {-5, 1, 5, 0, -7};

    // Create Solution object
    Solution obj;

    // Find the highest altitude
    int result = obj.largestAltitude(gain);

    // Print the answer
    cout << "Highest Altitude: " << result << endl;

    return 0;
}
