#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>> &intervals)
{
    // If there are no meetings, no room is required.
    if (intervals.empty())
        return 0;

    // ---------------------------------------------------------
    // STEP 1: Sort meetings according to start time.
    //
    // Example:
    //
    // [15,20], [0,30], [5,10]
    //
    // becomes:
    //
    // [0,30], [5,10], [15,20]
    // ---------------------------------------------------------
    sort(intervals.begin(), intervals.end());

    // ---------------------------------------------------------
    // Min Heap
    //
    // Stores END TIME of meetings currently using rooms.
    //
    // The smallest ending time is always at the top.
    //
    // Example:
    //
    // heap = [10,20,30]
    //          ↑
    //       earliest
    // ---------------------------------------------------------
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Maximum number of rooms required at any time.
    int maxRooms = 0;

    // ---------------------------------------------------------
    // STEP 2: Process every meeting.
    // ---------------------------------------------------------
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // -----------------------------------------------------
        // STEP 3:
        //
        // Remove meetings whose rooms are now free.
        //
        // If:
        //
        // earliest ending meeting <= current start
        //
        // then that room can be reused.
        // -----------------------------------------------------
        while (!minHeap.empty() && minHeap.top() <= start)
        {
            minHeap.pop();
        }

        // -----------------------------------------------------
        // STEP 4:
        //
        // Current meeting needs a room.
        // Store its end time.
        // -----------------------------------------------------
        minHeap.push(end);

        // -----------------------------------------------------
        // STEP 5:
        //
        // Number of elements in heap =
        // number of rooms currently being used.
        //
        // Keep the maximum.
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