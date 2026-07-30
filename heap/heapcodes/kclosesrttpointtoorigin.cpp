#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return k closest points to the origin (0,0)
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        //------------------------------------------------------
        // Max Heap
        //
        // pair.first               -> Distance from origin
        // pair.second.first        -> x coordinate
        // pair.second.second       -> y coordinate
        //
        // We use a Max Heap because:
        // - We only want to keep k closest points.
        // - If heap size becomes greater than k,
        //   remove the farthest point (largest distance).
        //------------------------------------------------------

        priority_queue<pair<int, pair<int, int>>> pq;

        //------------------------------------------------------
        // Traverse all points
        //------------------------------------------------------

        for (auto point : points)
        {

            int x = point[0];
            int y = point[1];

            //--------------------------------------------------
            // Calculate squared distance
            //
            // Distance = √(x² + y²)
            //
            // Square root is unnecessary because
            // √ is a monotonic function.
            //
            // Compare x²+y² instead.
            //--------------------------------------------------

            int dist = x * x + y * y;

            // Store distance and coordinates
            pq.push({dist, {x, y}});

            //--------------------------------------------------
            // Keep only k closest points
            //--------------------------------------------------

            if (pq.size() > k)
                pq.pop();
        }

        //------------------------------------------------------
        // Extract answer
        //------------------------------------------------------

        vector<vector<int>> ans;

        while (!pq.empty())
        {

            ans.push_back({pq.top().second.first,
                           pq.top().second.second});

            pq.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}};

    int k = 2;

    vector<vector<int>> ans = obj.kClosest(points, k);

    cout << "The " << k << " Closest Points are:\n";

    for (auto point : ans)
    {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}