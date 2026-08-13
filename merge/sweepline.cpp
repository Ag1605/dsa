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

    for (auto interval : intervals)
    {
        int start = interval[0];
        int end = interval[1];

        // Interval starts
        events.push_back({start, +1});

        // Interval ends
        events.push_back({end, -1});
    }

    // ---------------------------------------------------------
    // STEP 1: Sort events by time.
    //
    // Important:
    //
    // If start and end happen at the SAME time,
    // we process START first.
    //
    // Why?
    //
    // Problem says:
    //
    // [1,4] and [4,5]
    //
    // are overlapping because they share point 4.
    //
    // Therefore at time 4:
    //
    // +1 must come before -1.
    // ---------------------------------------------------------
    sort(events.begin(), events.end(),
         [](const pair<int, int> &a,
            const pair<int, int> &b)
         {
             // Different times:
             // smaller time comes first.
             if (a.first != b.first)
                 return a.first < b.first;

             // Same time:
             // +1 (start) comes before -1 (end).
             return a.second > b.second;
         });

    // Number of intervals currently active.
    int active = 0;

    // Maximum number of intervals active simultaneously.
    int maximum = 0;

    // ---------------------------------------------------------
    // STEP 2: Sweep through all events.
    //
    // +1 means an interval has started.
    // -1 means an interval has ended.
    // ---------------------------------------------------------
    for (auto event : events)
    {
        int time = event.first;
        int change = event.second;

        // Update number of active intervals.
        active += change;

        // Keep the maximum number seen so far.
        maximum = max(maximum, active);

        // Optional: print the sweep process
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