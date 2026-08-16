#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    vector<vector<int>> events;

    MyCalendar()
    {
    }

    bool book(int startTime, int endTime)
    {

        // Check the new interval with every
        // previously booked interval.
        for (int i = 0; i < events.size(); i++)
        {
            int start = events[i][0];
            int end = events[i][1];

            // Check if intervals overlap.
            //
            // New interval:      [startTime, endTime)
            // Existing interval: [start, end)
            //
            if (startTime < end && endTime > start)
            {
                // Double booking
                return false;
            }
        }

        // No overlap with any existing event,
        // so we can safely add the booking.
        events.push_back({startTime, endTime});

        return true;
    }
};

int main()
{
    MyCalendar myCalendar;

    cout << myCalendar.book(10, 20) << endl;
    cout << myCalendar.book(15, 25) << endl;
    cout << myCalendar.book(20, 30) << endl;

    return 0;
}