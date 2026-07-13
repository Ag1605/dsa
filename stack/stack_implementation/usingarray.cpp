#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    // Array to store stack elements
    int arr[1000];

    // Index of the top element
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Push an element onto the stack
    void push(int x)
    {
        // Check for overflow
        if (top == 999)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    // Remove the top element
    void pop()
    {
        // Check for underflow
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        top--;
    }

    // Return the top element
    int peek()
    {
        if (top == -1)
            return -1;

        return arr[top];
    }

    // Check if stack is empty
    bool empty()
    {
        return top == -1;
    }

    // Return the number of elements
    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.peek() << endl;

    // Pop one element
    st.pop();

    cout << "Top after pop: " << st.peek() << endl;

    cout << "Size: " << st.size() << endl;

    if (st.empty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}