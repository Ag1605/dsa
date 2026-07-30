#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum cost to connect all ropes
    int minCost(vector<int> &arr)
    {

        // -----------------------------
        // Min Heap
        // -----------------------------
        // Stores rope lengths in ascending order.
        // The smallest rope is always at the top.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert all rope lengths into the min heap
        for (int rope : arr)
        {
            pq.push(rope);
        }

        // Stores the total cost
        int cost = 0;

        // Continue until only one rope remains
        while (pq.size() > 1)
        {

            // Take the smallest rope
            int first = pq.top();
            pq.pop();

            // Take the second smallest rope
            int second = pq.top();
            pq.pop();

            // Cost to connect these two ropes
            int sum = first + second;

            // Add this cost to the total cost
            cost += sum;

            // Push the new combined rope back into the heap
            pq.push(sum);
        }

        // Return the minimum total cost
        return cost;
    }
};

int main()
{

    Solution obj;

    // Rope lengths
    vector<int> arr = {4, 3, 2, 6};

    cout << "Rope lengths: ";

    for (int rope : arr)
    {
        cout << rope << " ";
    }

    cout << endl;

    int answer = obj.minCost(arr);

    cout << "Minimum Cost = " << answer << endl;

    return 0;
}