#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    // Stack stores {price, span}
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner()
    {
    }

    int next(int price)
    {

        // Every new price has at least a span of 1
        int span = 1;

        // Remove all smaller or equal prices
        while (!st.empty() && st.top().first <= price)
        {

            // Add their spans
            span += st.top().second;

            st.pop();
        }

        // Store current price and its span
        st.push({price, span});

        return span;
    }
};

int main()
{

    StockSpanner obj;

    int n;
    cin >> n;

    while (n--)
    {

        int price;
        cin >> price;

        cout << obj.next(price) << " ";
    }

    return 0;
}