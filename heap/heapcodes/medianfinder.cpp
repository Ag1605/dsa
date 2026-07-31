#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{

public:
    //----------------------------------------------------------
    // Max Heap
    //
    // Stores the smaller half of the numbers.
    //
    // Example:
    // Numbers = 1 2 3
    //
    // Max Heap
    // Top = 3
    //----------------------------------------------------------

    priority_queue<int> leftHeap;

    //----------------------------------------------------------
    // Min Heap
    //
    // Stores the larger half of the numbers.
    //
    // Example:
    // Numbers = 7 8 9
    //
    // Min Heap
    // Top = 7
    //----------------------------------------------------------

    priority_queue<int, vector<int>, greater<int>> rightHeap;

    //----------------------------------------------------------
    // Constructor
    //----------------------------------------------------------

    MedianFinder()
    {
    }

    //----------------------------------------------------------
    // Insert a number
    //----------------------------------------------------------

    void addNum(int num)
    {

        //------------------------------------------------------
        // Step 1
        //
        // Decide which heap should receive the number.
        //
        // If number is smaller than the largest element of
        // the left heap, it belongs to the left half.
        //------------------------------------------------------

        if (leftHeap.empty() || num <= leftHeap.top())
        {

            leftHeap.push(num);
        }
        else
        {

            rightHeap.push(num);
        }

        //------------------------------------------------------
        // Step 2
        //
        // Balance the heaps.
        //
        // Their sizes should differ by at most one.
        //------------------------------------------------------

        // Left heap has two extra elements
        if (leftHeap.size() > rightHeap.size() + 1)
        {

            rightHeap.push(leftHeap.top());

            leftHeap.pop();
        }

        // Right heap has two extra elements
        else if (rightHeap.size() > leftHeap.size() + 1)
        {

            leftHeap.push(rightHeap.top());

            rightHeap.pop();
        }
    }

    //----------------------------------------------------------
    // Find Median
    //----------------------------------------------------------

    double findMedian()
    {

        //------------------------------------------------------
        // Case 1
        //
        // Both heaps have equal size.
        //
        // Median =
        // (largest element of left +
        //  smallest element of right) / 2
        //------------------------------------------------------

        if (leftHeap.size() == rightHeap.size())
        {

            return (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        //------------------------------------------------------
        // Case 2
        //
        // Left heap has one extra element.
        //------------------------------------------------------

        if (leftHeap.size() > rightHeap.size())
        {

            return leftHeap.top();
        }

        //------------------------------------------------------
        // Case 3
        //
        // Right heap has one extra element.
        //------------------------------------------------------

        return rightHeap.top();
    }
};

int main()
{

    MedianFinder obj;

    obj.addNum(1);

    cout << "Median = " << obj.findMedian() << endl;

    obj.addNum(2);

    cout << "Median = " << obj.findMedian() << endl;

    obj.addNum(3);

    cout << "Median = " << obj.findMedian() << endl;

    obj.addNum(4);

    cout << "Median = " << obj.findMedian() << endl;

    obj.addNum(5);

    cout << "Median = " << obj.findMedian() << endl;

    return 0;
}