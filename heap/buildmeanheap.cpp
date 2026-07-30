#include <bits/stdc++.h>
using namespace std;

class MinPriorityQueue
{
private:
    vector<int> heap;

public:
    // Insert element
    void push(int val)
    {

        heap.push_back(val);

        int i = heap.size() - 1;

        while (i > 0)
        {

            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);

            i = parent;
        }
    }

    // Remove minimum element
    void pop()
    {

        if (heap.empty())
        {
            cout << "Priority Queue is Empty\n";
            return;
        }

        // Move last element to root
        heap[0] = heap.back();

        // Remove last element
        heap.pop_back();

        int i = 0;

        while (true)
        {

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);

            i = smallest;
        }
    }

    int top()
    {

        if (heap.empty())
        {
            cout << "Priority Queue is Empty\n";
            return -1;
        }

        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }

    int size()
    {
        return heap.size();
    }

    void print()
    {

        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main()
{

    MinPriorityQueue pq;

    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(20);
    pq.push(15);

    cout << "Heap : ";
    pq.print();

    cout << "Top Element : " << pq.top() << endl;

    cout << "Size : " << pq.size() << endl;

    cout << "\nRemoving Elements:\n";

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}