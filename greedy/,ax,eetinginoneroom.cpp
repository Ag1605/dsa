
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {

        int n = start.size();

        // Step 1: Store meetings as {end time, start time}.
        // We put end time first because we want to sort by ending time.
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Step 2: Sort meetings in ascending order of ending time.
        // Meetings that finish earlier get priority.
        sort(meetings.begin(), meetings.end());

        // Step 3: Select the first meeting.
        int count = 1;

        // Store the ending time of the last selected meeting.
        int lastEnd = meetings[0].first;

        // Step 4: Check all remaining meetings.
        for (int i = 1; i < n; i++) {

            // Extract current meeting's start and end time.
            int currStart = meetings[i].second;
            int currEnd = meetings[i].first;

            // Check whether the current meeting starts
            // strictly after the previous selected meeting ends.
            if (currStart > lastEnd) {

                // Select the current meeting.
                count++;

                // Update the last selected meeting's ending time.
                lastEnd = currEnd;
            }
        }

        // Step 5: Return maximum number of meetings.
        return count;
    }
};

int main() {

    // Starting times of meetings.
    vector<int> start = {1, 3, 0, 5, 8, 5};

    // Ending times of meetings.
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution obj;

    int result = obj.maxMeetings(start, end);

    cout << "Maximum meetings that can be attended: "
         << result << endl;

    return 0;
}
