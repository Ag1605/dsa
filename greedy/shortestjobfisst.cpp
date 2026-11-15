
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& bt) {

        int n = bt.size();

        // Step 1: Sort burst times in ascending order.
        // Execute shorter processes before longer processes.
        sort(bt.begin(), bt.end());

        int waitingTime = 0;
        int totalWaitingTime = 0;

        // Step 2: Calculate waiting time for each process.
        for (int i = 0; i < n; i++) {

            // Current process must wait for all previous
            // processes to finish.
            totalWaitingTime += waitingTime;

            // Update waiting time by adding current
            // process's execution time.
            waitingTime += bt[i];
        }

        // Step 3: Calculate average waiting time.
        // Integer division automatically returns floor.
        return totalWaitingTime / n;
    }
};

int main() {

    // Burst time of each process.
    vector<int> bt = {4, 3, 7, 1};

    Solution obj;

    int result = obj.solve(bt);

    cout << "Minimum average waiting time: "
         << result << endl;

    return 0;
}
