#include <bits/stdc++.h>
using namespace std;

int maxSimultaneous(vector<vector<int>> &intervals)
{
    // ---------------------------------------------------------
    // EVENTS
    //
    // For every interval:
    //
    // [start, end]
    //
    // Create two events:
    //
    // start -> +1  (an interval starts)
    // end   -> -1  (an interval ends)
    // ---------------------------------------------------------

    vector<pair<int, int>> events;

    // Normal for loop instead of:
    // for(auto interval : intervals)
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Interval starts
        events.push_back({start, +1});

        // Interval ends
        events.push_back({end, -1});
    }

    // ---------------------------------------------------------
    // STEP 1: Sort events by time.
    //
    // If two events happen at the same time:
    //
    // +1 (start) comes BEFORE -1 (end)
    //
    // This means we consider:
    //
    // [1,4] and [4,5]
    //
    // as overlapping.
    // ---------------------------------------------------------

    sort(events.begin(), events.end(),
         [](const pair<int, int> &a,
            const pair<int, int> &b)
         {
             // Different times
             if (a.first != b.first)
             {
                 return a.first < b.first;
             }

             // Same time:
             // +1 comes before -1
             return a.second > b.second;
         });

    // Number of intervals currently active
    int active = 0;

    // Maximum number of intervals active simultaneously
    int maximum = 0;

    // ---------------------------------------------------------
    // STEP 2: Sweep through all events
    // ---------------------------------------------------------

    // Normal for loop
    for (int i = 0; i < events.size(); i++)
    {
        int time = events[i].first;
        int change = events[i].second;

        // Update active intervals
        active += change;

        // Update maximum
        maximum = max(maximum, active);

        // Print the sweep process
        cout << "Time: " << time
             << "  Change: " << change
             << "  Active: " << active << endl;
    }

    return maximum;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 4},
        {2, 5},
        {3, 6}};

    int answer = maxSimultaneous(intervals);

    cout << "\nMaximum simultaneous intervals: "
         << answer << endl;

    return 0;
}