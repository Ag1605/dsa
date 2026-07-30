#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the kth largest element
    int findKthLargest(vector<int> &nums, int k)
    {

        // -----------------------------
        // Min Heap
        // -----------------------------
        // We will store only the k largest elements.
        // The smallest among these k elements will always
        // be at the top of the heap.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Traverse every element in the array
        for (int num : nums)
        {

            // Insert current element into the heap
            pq.push(num);

            // If heap size becomes greater than k,
            // remove the smallest element.
            if (pq.size() > k)
                pq.pop();
        }

        // The top of the heap is the kth largest element.
        return pq.top();
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 2, 1, 5, 6, 4};

    int k = 2;

    cout << "Array : ";

    for (int x : nums)
        cout << x << " ";

    cout << endl;

    cout << "k = " << k << endl;

    cout << "Kth Largest Element = "
         << obj.findKthLargest(nums, k);

    return 0;
}