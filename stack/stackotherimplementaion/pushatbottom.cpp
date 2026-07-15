#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &st, int x)
{
    // Base case
    if(st.empty())
    {
        st.push(x);
        return;
    }

    // Store top element
    int topElement = st.top();
    st.pop();

    // Push x at bottom
    pushAtBottom(st, x);

    // Restore previous elements
    st.push(topElement);
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    pushAtBottom(st, 5);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}