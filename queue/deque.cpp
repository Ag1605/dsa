#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create a deque
    deque<int> dq;

    // ---------------- INSERT ----------------

    // Insert at front
    dq.push_front(20);
    dq.push_front(10);

    // Insert at rear
    dq.push_back(30);
    dq.push_back(40);

    // Deque:
    // 10 20 30 40

    // ---------------- ACCESS ----------------

    cout << "Front = " << dq.front() << endl;
    cout << "Back = " << dq.back() << endl;

    // ---------------- SIZE ----------------

    cout << "Size = " << dq.size() << endl;

    // ---------------- EMPTY ----------------

    if(dq.empty())
        cout << "Deque is Empty\n";
    else
        cout << "Deque is Not Empty\n";

    // ---------------- REMOVE ----------------

    // Remove front element
    dq.pop_front();

    // Remove rear element
    dq.pop_back();

    // Deque:
    // 20 30

    // ---------------- PRINT ----------------

    cout << "Deque Elements : ";

    for(int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}