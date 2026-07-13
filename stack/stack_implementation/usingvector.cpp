#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    // Vector to store stack elements
    vector<int> v;

public:
    // Push an element onto the stack
    void push(int x)
    {
        v.push_back(x);
    }

    // Remove the top element
    void pop()
    {
        if (!v.empty())
            v.pop_back();
    }

    // Return the top element
    int top()
    {
        if (!v.empty())
            return v.back();

        return -1; // Stack is empty
    }

    // Check whether the stack is empty
    bool empty()
    {
        return v.empty();
    }

    // Return the number of elements in the stack
    int size()
    {
        return v.size();
    }
};

int main()
{
    Stack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.top() << endl;

    // Remove the top element
    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    if (st.empty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}