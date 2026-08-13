#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>> &intervals)
{
    // If there are no meetings, no room is required.
    if (intervals.empty())
        return 0;

    // ---------------------------------------------------------
    // STEP 1: Sort meetings according to their start time.
    //
    // Example:
    // [5,10], [0,30], [15,20]
    //
    // becomes:
    // [0,30], [5,10], [15,20]
    // ---------------------------------------------------------
    sort(intervals.begin(), intervals.end());

    // ---------------------------------------------------------
    // Min Heap
    //
    // It stores the END TIME of every meeting that is
    // currently using a room.
    //
    // The smallest end time will always be at the top.
    //
    // Example:
    //
    // heap = [10, 20, 30]
    //          ↑
    //       earliest
    // ---------------------------------------------------------
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Stores the maximum number of rooms used at any time.
    int maxRooms = 0;

    // Process every meeting one by one.
    for (auto interval : intervals)
    {
        int start = interval[0];
        int end = interval[1];

        // -----------------------------------------------------
        // STEP 2:
        // Remove all meetings whose rooms are now free.
        //
        // If the earliest ending meeting ends at or before
        // the current meeting's start time, we can reuse
        // that room.
        //
        // Example:
        //
        // Current meeting: [15,20]
        // Earliest ending meeting: 10
        //
        // 10 <= 15
        //
        // So that room is free.
        // -----------------------------------------------------
        while (!minHeap.empty() && minHeap.top() <= start)
        {
            minHeap.pop();
        }

        // -----------------------------------------------------
        // STEP 3:
        // Current meeting needs a room.
        //
        // Store its ending time in the heap.
        // -----------------------------------------------------
        minHeap.push(end);

        // -----------------------------------------------------
        // STEP 4:
        // Heap size = number of rooms currently being used.
        //
        // Keep track of the maximum number of rooms required.
        // -----------------------------------------------------
        maxRooms = max(maxRooms, (int)minHeap.size());
    }

    return maxRooms;
}

int main()
{
    vector<vector<int>> intervals = {
        {0, 30},
        {5, 10},
        {15, 20}};

    int answer = minMeetingRooms(intervals);

    cout << "Minimum rooms required: " << answer << endl;

    return 0;
}