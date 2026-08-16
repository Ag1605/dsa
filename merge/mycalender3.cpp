#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
public:
    // events stores changes in the number of active bookings.
    //
    // +1 -> an event starts
    // -1 -> an event ends
    //
    // map automatically keeps the times sorted.
    //
    // Example:
    // book(10, 20)
    //
    // events:
    // 10 -> +1
    // 20 -> -1
    //
    map<int, int> events;

    int book(int startTime, int endTime)
    {

        // =========================================================
        // STEP 1: MARK THE START OF THE EVENT
        // =========================================================
        //
        // At startTime, one new booking becomes active.
        //
        // Example:
        // book(10, 20)
        //
        // At time 10:
        // active bookings increase by 1.
        //
        events[startTime]++;

        // =========================================================
        // STEP 2: MARK THE END OF THE EVENT
        // =========================================================
        //
        // At endTime, this booking is no longer active.
        //
        // Therefore we decrease the active booking count by 1.
        //
        events[endTime]--;

        // active = number of bookings currently active
        int active = 0;

        // maximum = maximum number of simultaneous bookings
        int maximum = 0;

        // =========================================================
        // STEP 3: SWEEP THROUGH ALL TIMES
        // =========================================================
        //
        // map stores keys in sorted order.
        //
        // For example:
        //
        // events:
        //
        // 10 -> +1
        // 15 -> +1
        // 20 -> -1
        // 25 -> -1
        //
        // We process them from left to right.
        //
        for (auto it = events.begin(); it != events.end(); it++)
        {

            // Apply the change at the current time.
            //
            // If +1:
            //     one booking starts.
            //
            // If -1:
            //     one booking ends.
            //
            active += it->second;

            // Keep track of the highest number of
            // simultaneously active bookings.
            maximum = max(maximum, active);
        }

        // Return the maximum number of bookings
        // that overlap at any point in time.
        return maximum;
    }
};

int main()
{

    MyCalendarThree calendar;

    cout << boolalpha;

    // ---------------------------------------------------------
    // First booking
    // ---------------------------------------------------------
    cout << calendar.book(10, 20) << endl;

    // Events:
    //
    // 10 -> +1
    // 20 -> -1
    //
    // Sweep:
    //
    // time 10:
    // active = 1
    //
    // time 20:
    // active = 0
    //
    // maximum = 1
    //
    // Output: 1

    // ---------------------------------------------------------
    // Second booking
    // ---------------------------------------------------------
    cout << calendar.book(15, 25) << endl;

    // Bookings:
    //
    // [10,20]
    // [15,25]
    //
    // Between 15 and 20:
    //
    //       [10---------20]
    //            [15---------25]
    //
    //              ↑
    //         2 bookings
    //
    // Output: 2

    // ---------------------------------------------------------
    // Third booking
    // ---------------------------------------------------------
    cout << calendar.book(20, 30) << endl;

    // Bookings:
    //
    // [10,20]
    // [15,25]
    // [20,30]
    //
    // Maximum overlap is still 2.
    //
    // Output: 2

    // ---------------------------------------------------------
    // Fourth booking
    // ---------------------------------------------------------
    cout << calendar.book(17, 22) << endl;

    // Now:
    //
    // [10,20]
    // [15,25]
    // [20,30]
    // [17,22]
    //
    // Between 17 and 20:
    //
    // [10---------20]
    //      [15---------25]
    //          [17-----22]
    //
    // Three bookings are active.
    //
    // Maximum = 3
    //
    // Output: 3

    return 0;
}