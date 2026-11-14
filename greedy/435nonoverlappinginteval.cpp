
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
// same like actsel but we used comparator beacuse simple array approch same;
    // Step 1: Comparator function
    // Sort intervals in ascending order of ending time.
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Handle empty input.
        if (n == 0) {
            return 0;
        }

        // Step 2: Sort intervals by ending time.
        // Greedy strategy: Always prefer the interval
        // that finishes earliest.
        sort(intervals.begin(), intervals.end(), comp);

        // Step 3: Select the first interval.
        int count = 1;

        // Store the ending time of the last selected interval.
        int lastEnd = intervals[0][1];

        // Step 4: Traverse the remaining intervals.
        for (int i = 1; i < n; i++) {

            // Check whether the current interval overlaps
            // with the previously selected interval.
            if (intervals[i][0] >= lastEnd) {

                // No overlap: Select this interval.
                count++;

                // Update the ending time.
                lastEnd = intervals[i][1];
            }

            // Otherwise, skip this interval.
            // It will be considered as an interval to remove.
        }

        // Step 5:
        // Minimum removals = Total intervals - Maximum
        // number of non-overlapping intervals.
        return n - count;
    }
};

int main() {

    // Given intervals: {start, end}
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    Solution obj;

    int result = obj.eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << result << endl;

    return 0;
}
