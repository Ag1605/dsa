#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(1);

    cout << "Top: " << minHeap.top() << endl; // 1

    minHeap.pop();

    cout << "Top after pop: " << minHeap.top() << endl; // 5

    return 0;
}