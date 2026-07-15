#include <bits/stdc++.h>
using namespace std;

// ===============================
// Approach 1 : Recursion
// ===============================

// Push element at bottom
void pushAtBottom(stack<int> &st, int x)
{
    // Base Case
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();

    pushAtBottom(st, x);

    st.push(topElement);
}

// Reverse using recursion
void reverseStackRecursion(stack<int> &st)
{
    // Base Case
    if (st.empty())
        return;

    int topElement = st.top();
    st.pop();

    // Reverse remaining stack
    reverseStackRecursion(st);

    // Put removed element at bottom
    pushAtBottom(st, topElement);
}

// ===============================
// Approach 2 : Extra Stack
// ===============================

void reverseStackExtraStack(stack<int> &st)
{
    stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st = temp;
}

// ===============================
// Print Stack
// ===============================

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// ===============================
// Main Function
// ===============================

int main()
{
    stack<int> st1, st2;

    // Original Stack
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);

    // Copy for second approach
    st2 = st1;

    cout << "Original Stack (Top -> Bottom): ";
    printStack(st1);

    // Recreate st1 because printStack takes copy,
    // but let's keep code clear.
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);

    // -------------------------------
    // Approach 1
    // -------------------------------
    reverseStackRecursion(st1);

    cout << "Recursion Reverse: ";
    printStack(st1);

    // -------------------------------
    // Approach 2
    // -------------------------------
    reverseStackExtraStack(st2);

    cout << "Extra Stack Reverse: ";
    printStack(st2);

    return 0;
}