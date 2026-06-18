#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int>& newInterval)
{
    // Step 1: Insert new interval
    intervals.push_back(newInterval);

    // Step 2: Sort intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    int n = intervals.size();

    int start = intervals[0][0];
    int end = intervals[0][1];

    // Step 3: Merge intervals
    for(int i = 1; i < n; i++)
    {
        int s = intervals[i][0];
        int e = intervals[i][1];

        if(end >= s) // overlap
        {
            end = max(end, e);
        }
        else
        {
            res.push_back({start, end});

            start = s;
            end = e;
        }
    }

    // Push last interval
    res.push_back({start, end});

    return res;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10},
        {12, 16}
    };

    vector<int> newInterval = {4, 8};

    vector<vector<int>> ans =
        insertInterval(intervals, newInterval);

    cout << "Result:\n";

    for(auto interval : ans)
    {
        cout << "[" << interval[0]
             << "," << interval[1]
             << "] ";
    }

    return 0;
}