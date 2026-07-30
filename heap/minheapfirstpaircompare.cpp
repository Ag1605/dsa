#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int main()
{

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        Compare>
        pq;

    pq.push({10, 1});
    pq.push({5, 2});
    pq.push({20, 3});
    pq.push({15, 4});

    while (!pq.empty())
    {
        cout << pq.top().first << " "
             << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}