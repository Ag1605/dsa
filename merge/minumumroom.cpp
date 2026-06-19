#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<int>& start,
                    vector<int>& end)
{
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int n = start.size();

    int i = 0;
    int j = 0;

    int rooms = 0;
    int ans = 0;

    while(i < n)
    {
        if(start[i] < end[j])
        {
            rooms++;
            ans = max(ans, rooms);
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    return ans;
}

int main()
{
    vector<int> start = {2,9,6};
    vector<int> end = {4,12,10};

    cout << minMeetingRooms(start, end);

    return 0;
}