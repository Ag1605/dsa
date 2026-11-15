
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:

    // find() returns the latest available time slot.
    // DSU (Disjoint Set Union) helps us find an available slot efficiently.
    int find(int x, vector<int>& parent) {

        // If parent[x] == x, this slot is available.
        if (parent[x] == x) {
            return x;
        }

        // Path compression:
        // Directly connect this slot to its representative.
        return parent[x] = find(parent[x], parent);
    }

public:
    vector<int> jobSequencing(vector<int>& deadline,
                              vector<int>& profit) {

        int n = deadline.size();

        // Step 1: Store each job as {profit, deadline}.
        // We store profit first because we want to sort by profit.
        vector<pair<int, int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: Sort jobs in descending order of profit.
        // We want to consider the most profitable jobs first.
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

        // Step 3: Find the maximum deadline.
        // This tells us the maximum number of possible time slots.
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Step 4: Initialize the DSU parent array.
        // Initially, every slot is available.
        // Slot 0 represents that no valid slot is available.
        vector<int> parent(maxDeadline + 1);

        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int count = 0;       // Number of jobs completed.
        int totalProfit = 0; // Total profit earned.

        // Step 5: Process jobs in decreasing order of profit.
        for (int i = 0; i < n; i++) {

            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;

            // Find the latest available slot before or on the deadline.
            int slot = find(currDeadline, parent);

            // If slot > 0, we found an available slot.
            if (slot > 0) {

                // Schedule this job.
                count++;

                // Add its profit.
                totalProfit += currProfit;

                // Mark this slot as occupied.
                // Now the previous slot becomes the representative.
                parent[slot] = find(slot - 1, parent);
            }
        }

        // Return:
        // Index 0 = Number of jobs completed.
        // Index 1 = Maximum total profit.
        return {count, totalProfit};
    }
};

int main() {

    // Given job deadlines.
    vector<int> deadline = {4, 1, 1, 1};

    // Given job profits.
    vector<int> profit = {20, 10, 40, 30};

    Solution obj;

    // Call the job sequencing function.
    vector<int> result = obj.jobSequencing(deadline, profit);

    // Print the result.
    cout << "Number of jobs completed: " << result[0] << endl;

    cout << "Maximum total profit: " << result[1] << endl;

    return 0;
}
