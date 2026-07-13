#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create a queue
    queue<int> q;

    // ---------------- PUSH ----------------
    // Insert elements at the rear
    q.push(10);
    q.push(20);
    q.push(30);

    // Queue:
    // Front -> 10 20 30 <- Rear

    // ---------------- FRONT ----------------
    cout << "Front Element: " << q.front() << endl;

    // ---------------- BACK ----------------
    cout << "Rear Element: " << q.back() << endl;

    // ---------------- SIZE ----------------
    cout << "Size: " << q.size() << endl;

    // ---------------- EMPTY ----------------
    if (q.empty())
        cout << "Queue is Empty\n";
    else
        cout << "Queue is Not Empty\n";

    // ---------------- POP ----------------
    // Removes front element
    q.pop();

    // Queue:
    // Front -> 20 30

    cout << "Front after Pop: " << q.front() << endl;

    // ---------------- PRINT ----------------
    // Make a copy because pop() removes elements
    queue<int> temp = q;

    cout << "Queue Elements: ";

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;

    return 0;
}