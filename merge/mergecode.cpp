#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());

    int n = intervals.size();

    int start = intervals[0][0];
    int end = intervals[0][1];

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

    res.push_back({start, end});

    return res;
}

int main()
{
    vector<vector<int>> intervals = {
        {4,7},
        {1,4},
        {8,10},
        {9,12},
        {15,18}
    };

    vector<vector<int>> ans = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";

    for(auto interval : ans)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}