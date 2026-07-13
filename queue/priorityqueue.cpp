#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Max Heap
    priority_queue<int> pq;

    // ---------------- INSERT ----------------

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    // ---------------- TOP ----------------

    cout << "Top = " << pq.top() << endl;

    // ---------------- SIZE ----------------

    cout << "Size = " << pq.size() << endl;

    // ---------------- EMPTY ----------------

    if (pq.empty())
        cout << "Priority Queue is Empty\n";
    else
        cout << "Priority Queue is Not Empty\n";

    // ---------------- POP ----------------

    pq.pop();

    cout << "Top After Pop = " << pq.top() << endl;

    // ---------------- PRINT ----------------

    priority_queue<int> temp = pq;

    cout << "Elements : ";

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    return 0;
}