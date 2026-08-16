#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {

        // =========================================================
        // STEP 1: SORT INTERVALS BY STARTING TIME
        // =========================================================
        //
        // Example:
        //
        // [5,10]
        // [1,5]
        // [2,6]
        //
        // After sorting:
        //
        // [1,5]
        // [2,6]
        // [5,10]
        //
        // This allows us to process intervals from left to right.
        //
        sort(intervals.begin(), intervals.end());

        // =========================================================
        // STEP 2: CREATE A MIN HEAP
        // =========================================================
        //
        // The priority queue stores the ENDING TIME of intervals
        // currently occupying groups.
        //
        // We need the smallest ending time quickly because the
        // group that finishes earliest is the first group we can
        // potentially reuse.
        //
        // greater<int> makes this a MIN HEAP.
        //
        // Example:
        //
        // pq = {5, 8, 12}
        //
        // pq.top() = 5
        //
        priority_queue<int, vector<int>, greater<int>> pq;

        // =========================================================
        // STEP 3: PROCESS EACH INTERVAL
        // =========================================================
        //
        for (int i = 0; i < intervals.size(); i++)
        {

            int left = intervals[i][0];
            int right = intervals[i][1];

            // =====================================================
            // STEP 4: CHECK WHETHER AN EXISTING GROUP CAN BE REUSED
            // =====================================================
            //
            // pq.top() gives the interval that ends earliest.
            //
            // If:
            //
            // pq.top() < left
            //
            // then that interval has completely finished before
            // the current interval starts.
            //
            // Therefore, we can reuse that group.
            //
            // IMPORTANT:
            //
            // Intervals are considered CLOSED:
            //
            // [1,5] and [5,10]
            //
            // overlap at point 5.
            //
            // Therefore we need:
            //
            // pq.top() < left
            //
            // NOT:
            //
            // pq.top() <= left
            //
            if (!pq.empty() && pq.top() < left)
            {

                // Remove the ending time of the finished interval.
                // Its group is now available.
                pq.pop();
            }

            // =====================================================
            // STEP 5: PUT CURRENT INTERVAL INTO A GROUP
            // =====================================================
            //
            // Whether we reused an existing group or need a new
            // group, the current interval now occupies a group.
            //
            // Store its ending time in the heap.
            //
            pq.push(right);
        }

        // =========================================================
        // STEP 6: RETURN NUMBER OF GROUPS
        // =========================================================
        //
        // Each value currently in the heap represents one group
        // that is occupied by an interval.
        //
        // The heap size therefore represents the number of groups
        // required.
        //
        return pq.size();
    }
};

int main()
{

    Solution solution;

    // =========================================================
    // TEST CASE 1
    // =========================================================

    vector<vector<int>> intervals1 = {
        {5, 10},
        {6, 8},
        {1, 5},
        {2, 3}};

    cout << solution.minGroups(intervals1) << endl;

    // Sorted intervals:
    //
    // [1,5]
    // [2,3]
    // [5,10]
    // [6,8]
    //
    // Groups required:
    //
    // Group 1: [1,5]
    // Group 2: [2,3]
    // Group 3: [5,10]
    // Group 4: [6,8]
    //
    // Answer = 2
    //
    // Actually:
    //
    // [1,5] and [5,10] CANNOT share a group
    // because they overlap at 5.
    //
    // But [2,3] can share with [5,10].
    //
    // So:
    //
    // Group 1: [1,5] [6,8]
    // Group 2: [2,3] [5,10]
    //
    // Answer = 2

    // =========================================================
    // TEST CASE 2
    // =========================================================

    vector<vector<int>> intervals2 = {
        {1, 10},
        {2, 5},
        {6, 8}};

    cout << solution.minGroups(intervals2) << endl;

    // [1,10] overlaps with both [2,5] and [6,8].
    //
    // Therefore at least 2 groups are required.
    //
    // Group 1: [1,10]
    // Group 2: [2,5] [6,8]
    //
    // Answer = 2

    return 0;
}