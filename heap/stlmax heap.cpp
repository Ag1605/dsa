#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Top element (maximum)
    cout << "Top: " << pq.top() << endl; // 30

    // Remove top element
    pq.pop();

    cout << "Top after pop: " << pq.top() << endl; // 20

    // Size
    cout << "Size: " << pq.size() << endl;

    // Check if empty
    if (pq.empty())
        cout << "Empty";
    else
        cout << "Not Empty";

    return 0;
}