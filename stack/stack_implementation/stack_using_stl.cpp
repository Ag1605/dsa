#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Create a stack of integers
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Print top element
    cout << "Top Element: " << st.top() << endl;

    // Remove the top element
    st.pop();

    // Print top element after pop
    cout << "Top after pop: " << st.top() << endl;

    // Print size
    cout << "Size: " << st.size() << endl;

    // Check if stack is empty
    if (st.empty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}