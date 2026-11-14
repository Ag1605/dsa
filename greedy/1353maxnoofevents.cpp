
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        int n = events.size();

        // Step 1: Sort events by starting day.
        // Each event contains {startDay, endDay}.
        sort(events.begin(), events.end());

        // Step 2: Create a Min Heap.
        // It stores the ending days of available events.
        // The event with the earliest ending day stays at the top.
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0;       // Tracks events that are not added yet.
        int day = 1;     // Current day.
        int count = 0;   // Total events attended.

        // Continue while unprocessed events exist
        // or the heap still contains available events.
        while (i < n || !pq.empty()) {

            // Step 3: If no event is available,
            // jump directly to the next event's starting day.
            if (pq.empty()) {
                day = events[i][0];
            }

            // Step 4: Add all events that have started
            // on or before the current day.
            while (i < n && events[i][0] <= day) {

                // Store the ending day in the Min Heap.
                pq.push(events[i][1]);

                i++;
            }

            // Step 5: Remove expired events.
            // An event is expired if its ending day is
            // earlier than the current day.
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Step 6: Attend the event that ends earliest.
            if (!pq.empty()) {

                // Remove the event from the heap
                // because we are attending it today.
                pq.pop();

                count++;

                // Move to the next day.
                day++;
            }
        }

        // Step 7: Return maximum number of events attended.
        return count;
    }
};

int main() {

    // Each event is represented as {startDay, endDay}.
    vector<vector<int>> events = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    Solution obj;

    int result = obj.maxEvents(events);

    cout << "Maximum events attended: " << result << endl;

    return 0;
}
