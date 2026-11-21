
#include <bits/stdc++.h>
using namespace std;


// FUNCTION 1: Insert an element at the bottom of stack
void insertAtBottom(stack<int>& st, int x)
{
    // BASE CASE:
    // If stack becomes empty, we have reached the bottom.
    // Insert x here.
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // STEP 1:
    // Store the current top element.
    int num = st.top();

    // STEP 2:
    // Remove the top element temporarily.
    st.pop();

    // STEP 3:
    // Recursively reach the bottom of the stack.
    insertAtBottom(st, x);

    // STEP 4:
    // Restore the removed element.
    // This happens while recursion returns.
    st.push(num);
}


// FUNCTION 2: Reverse the entire stack
void reverseStack(stack<int>& st)
{
    // BASE CASE:
    // An empty stack or a stack with one element
    // is already reversed.
    if (st.empty())
    {
        return;
    }

    // STEP 1:
    // Store the top element.
    int num = st.top();

    // STEP 2:
    // Remove the top element.
    st.pop();

    // STEP 3:
    // Recursively reverse the remaining stack.
    reverseStack(st);

    // STEP 4:
    // Insert the removed element at the bottom.
    insertAtBottom(st, num);
}


int main()
{
    // Create a stack.
    stack<int> st;

    // Insert elements into the stack.
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // Original stack:
    // TOP -> 5, 4, 3, 2, 1 -> BOTTOM

    // Reverse the stack.
    reverseStack(st);

    // Print the reversed stack.
    cout << "Reversed Stack (Top to Bottom): ";

    while (!st.empty())
    {
        cout << st.top() << " ";

        // Remove the printed element.
        st.pop();
    }

    cout << endl;

    return 0;
}
