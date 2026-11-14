
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int activitySelection(vector<int>& start, vector<int>& finish) {

        int n = start.size();

        // Step 1: Store activities as {finish time, start time}
        // We store finish time first because we want to sort by finish time.
        vector<pair<int, int>> act;

        for (int i = 0; i < n; i++) {
            act.push_back({finish[i], start[i]});
        }

        // Step 2: Sort activities in ascending order of finish time.
        // Activity that finishes earliest comes first.
        sort(act.begin(), act.end());

        // Step 3: Select the first activity.
        int count = 1;

        // Keep track of the finish time of the last selected activity.
        int lastFinish = act[0].first;

        // Step 4: Check all remaining activities.
        for (int i = 1; i < n; i++) {

            // Extract current activity's start and finish time.
            int curFinish = act[i].first;
            int curStart = act[i].second;

            // Select current activity only if it starts
            // strictly AFTER the previous activity finishes.
            if (curStart > lastFinish) {

                count++;

                // Update the finish time of the last selected activity.
                lastFinish = curFinish;
            }
        }

        // Step 5: Return maximum number of non-overlapping activities.
        return count;
    }
};

int main() {

    // Starting times of activities.
    vector<int> start = {1, 3, 0, 5, 8, 5};

    // Finishing times of activities.
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    // Create Solution object.
    Solution obj;

    // Call activitySelection function.
    int result = obj.activitySelection(start, finish);

    // Print maximum number of activities.
    cout << "Maximum activities selected: " << result << endl;

    return 0;
}
