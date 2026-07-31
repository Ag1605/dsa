#include <bits/stdc++.h>
using namespace std;

class KthLargest
{

public:
    //----------------------------------------------------------
    // Min Heap
    //
    // The heap stores only the k largest elements seen so far.
    //
    // Why Min Heap?
    //
    // The smallest element among these k largest elements
    // will be the kth largest element.
    //
    // Example:
    //
    // k = 3
    //
    // Numbers = 2 4 8 10 15
    //
    // Heap stores:
    //
    // 8 10 15
    //
    // Heap Top = 8
    //
    // 8 is the 3rd largest element.
    //----------------------------------------------------------

    priority_queue<int, vector<int>, greater<int>> pq;

    //----------------------------------------------------------
    // Store value of k
    //----------------------------------------------------------

    int k;

    //----------------------------------------------------------
    // Constructor
    //----------------------------------------------------------

    KthLargest(int k, vector<int> &nums)
    {

        // Save k in class variable
        this->k = k;

        //------------------------------------------------------
        // Insert every element into heap
        //------------------------------------------------------

        for (int num : nums)
        {

            pq.push(num);

            //--------------------------------------------------
            // Heap should contain only k elements
            //--------------------------------------------------

            if (pq.size() > k)
            {

                // Remove smallest element
                pq.pop();
            }
        }
    }

    //----------------------------------------------------------
    // Add a new value into the stream
    //----------------------------------------------------------

    int add(int val)
    {

        //------------------------------------------------------
        // Insert new number
        //------------------------------------------------------

        pq.push(val);

        //------------------------------------------------------
        // Keep only k largest elements
        //------------------------------------------------------

        if (pq.size() > k)
        {

            pq.pop();
        }

        //------------------------------------------------------
        // Heap top = kth largest element
        //------------------------------------------------------

        return pq.top();
    }
};

int main()
{

    //----------------------------------------------------------
    // Initial numbers
    //----------------------------------------------------------

    vector<int> nums = {4, 5, 8, 2};

    //----------------------------------------------------------
    // k = 3
    //----------------------------------------------------------

    KthLargest obj(3, nums);

    cout << "After adding 3  -> " << obj.add(3) << endl;

    cout << "After adding 5  -> " << obj.add(5) << endl;

    cout << "After adding 10 -> " << obj.add(10) << endl;

    cout << "After adding 9  -> " << obj.add(9) << endl;

    cout << "After adding 4  -> " << obj.add(4) << endl;

    return 0;
}