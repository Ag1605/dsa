#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    // bookings stores ALL successfully accepted events.
    // Example: [10, 20] means an event from time 10 to 20.
    vector<vector<int>> bookings;

    // overlaps stores intervals where there are ALREADY 2 bookings.
    // If a new event overlaps with anything in this vector,
    // it would create a triple booking.
    vector<vector<int>> overlaps;

    bool book(int startTime, int endTime) {

        // =========================================================
        // STEP 1: CHECK FOR TRIPLE BOOKING
        // =========================================================
        //
        // overlaps contains areas where TWO events are already
        // booked at the same time.
        //
        // If our new event overlaps with any such interval,
        // then at that time:
        //
        //     Old Event 1
        //     Old Event 2
        //     New Event
        //
        // would all exist together -> TRIPLE BOOKING.
        //
        for (int i = 0; i < overlaps.size(); i++) {

            int start = overlaps[i][0];
            int end = overlaps[i][1];

            // Find intersection between:
            // [startTime, endTime)
            // and
            // [start, end)
            //
            // The intersection starts at the LARGER start.
            int s = max(startTime, start);

            // The intersection ends at the SMALLER end.
            int e = min(endTime, end);

            // If s < e, there is a real overlapping interval.
            //
            // Example:
            // New event     = [15, 25]
            // Double booked = [20, 30]
            //
            // s = max(15,20) = 20
            // e = min(25,30) = 25
            //
            // 20 < 25 -> overlap exists -> TRIPLE BOOKING.
            if (s < e) {
                return false;
            }
        }


        // =========================================================
        // STEP 2: FIND NEW DOUBLE-BOOKED INTERVALS
        // =========================================================
        //
        // Now we know that adding the new event will NOT create
        // a triple booking.
        //
        // But the new event may overlap with existing bookings.
        //
        // Whenever it overlaps with an existing booking,
        // that common part becomes DOUBLE BOOKED.
        //
        for (int i = 0; i < bookings.size(); i++) {

            int start = bookings[i][0];
            int end = bookings[i][1];

            // Find intersection between:
            // New booking  = [startTime, endTime)
            // Old booking  = [start, end)
            int s = max(startTime, start);
            int e = min(endTime, end);

            // If s < e, the two events overlap.
            if (s < e) {

                // Store the overlapping part because this interval
                // is now booked by TWO events.
                overlaps.push_back({s, e});
            }
        }


        // =========================================================
        // STEP 3: ADD THE NEW BOOKING
        // =========================================================
        //
        // Since no triple booking was found, the event is valid.
        // Add it to bookings.
        //
        bookings.push_back({startTime, endTime});


        // Booking was successfully added.
        return true;
    }
};


int main() {

    // Create our calendar object.
    MyCalendarTwo calendar;

    // =========================================================
    // TEST CASE
    // =========================================================

    cout << boolalpha;

    cout << calendar.book(10, 20) << endl;
    // true
    //
    // bookings:
    // [10,20]
    //
    // overlaps:
    // empty


    cout << calendar.book(15, 25) << endl;
    // true
    //
    // [10,20] and [15,25] overlap from [15,20]
    //
    // bookings:
    // [10,20]
    // [15,25]
    //
    // overlaps:
    // [15,20]


    cout << calendar.book(20, 30) << endl;
    // true
    //
    // New event [20,30]
    //
    // It does NOT overlap with [15,20]
    // because the interval ends at 20.
    //
    // bookings:
    // [10,20]
    // [15,25]
    // [20,30]
    //
    // overlaps:
    // [15,20]
    // [20,25]


    cout << calendar.book(17, 22) << endl;
    // false
    //
    // [17,22] overlaps with [15,20]
    // which is already double booked.
    //
    // Therefore adding [17,22] would create
    // a triple booking.
    
    return 0;
}