#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

int main()
{

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        Compare>
        pq;

    pq.push({1, 30});
    pq.push({2, 10});
    pq.push({3, 20});

    while (!pq.empty())
    {
        cout << pq.top().first << " "
             << pq.top().second << endl;
        pq.pop();
    }
}