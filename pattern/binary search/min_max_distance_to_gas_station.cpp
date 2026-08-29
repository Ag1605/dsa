#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Checks whether we can make the maximum gap <= dist
    // using at most k new stations.
    bool canplace(vector<int>& arr, int k, double dist) {

        // Number of new stations required
        int stationneeded = 0;

        // Check every gap between adjacent existing stations
        for (int i = 1; i < arr.size(); i++) {

            // Find the gap between current and previous station
            double gap = arr[i] - arr[i - 1];

            /*
                Suppose gap = 10 and dist = 3

                We need to divide 10 into parts of size <= 3.

                10 / 3 = 3.33
                ceil(3.33) = 4 parts

                To create 4 parts, we need 3 new stations.

                Therefore:
                new stations = ceil(gap / dist) - 1
            */
            stationneeded += ceil(gap / dist) - 1;

            // If we need more than k stations,
            // this distance is not possible.
            if (stationneeded > k) {
                return false;
            }
        }

        // We can achieve this distance using <= k stations
        return true;
    }


    // Finds the minimum possible maximum distance
    // between any two adjacent gas stations.
    long double minimiseMaxDistance(vector<int>& arr, int k) {

        // Smallest possible answer
        double low = 0;

        // Largest gap between existing stations
        double high = 0;

        // Find the maximum existing gap
        for (int i = 1; i < arr.size(); i++) {
            high = max(high, (double)(arr[i] - arr[i - 1]));
        }

        /*
            Binary search on the answer.

            We stop when the difference between high and low
            becomes smaller than 1e-6.

            1e-6 = 0.000001
        */
        while (high - low > 1e-6) {

            // Find middle distance
            double mid = low + (high - low) / 2;

            /*
                If mid is possible:
                    We try to find an even smaller distance.
                    So move high to mid.

                If mid is not possible:
                    We need a larger distance.
                    So move low to mid.
            */
            if (canplace(arr, k, mid)) {
                high = mid;
            }
            else {
                low = mid;
            }
        }

        // high is our final answer
        return high;
    }
};


int main() {

    // Positions of existing gas stations
    vector<int> arr = {1, 10, 20};

    // Number of new gas stations we can add
    int k = 2;

    // Create object of Solution class
    Solution obj;

    // Calculate the answer
    long double answer = obj.minimiseMaxDistance(arr, k);

    // Print answer up to 6 decimal places
    cout << fixed << setprecision(6);
    cout << "Minimum maximum distance = " << answer << endl;

    return 0;
}