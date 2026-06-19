#include <bits/stdc++.h>
using namespace std;

bool overlap(vector<vector<int>>& a)
{
    sort(a.begin(), a.end());

    int n = a.size();

    int start1 = a[0][0];
    int end1 = a[0][1];

    for(int i = 1; i < n; i++)
    {
        int start2 = a[i][0];
        int end2 = a[i][1];

        // overlap found
        if(end1 >= start2)
        {
            return true;
        }

        // update current interval
        end1 = max(end1, end2);
    }

    return false;
}

int main()
{
    vector<vector<int>> arr = {
        {1,3},
        {5,7},
        {2,4},
        {6,8}
    };

    if(overlap(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}