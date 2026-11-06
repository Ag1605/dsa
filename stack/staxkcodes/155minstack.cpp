
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:

    // Normal stack stores all elements
    stack<int> st;

    // Minimum stack stores the minimum
    // element at every corresponding position
    stack<int> minSt;

    // Constructor
    MinStack() {

        // Initially both stacks are empty
    }

    // Step 1: Push an element
    void push(int val) {

        // Push the value into the normal stack
        st.push(val);

        // If minimum stack is empty,
        // current value is the minimum
        if (minSt.empty()) {

            minSt.push(val);
        }
        else {

            // Compare current value with previous minimum
            // Store whichever value is smaller
            minSt.push(min(val, minSt.top()));
        }
    }

    // Step 2: Remove the top element
    void pop() {

        // Remove the top element from both stacks
        st.pop();
        minSt.pop();
    }

    // Step 3: Return the top element
    int top() {

        return st.top();
    }

    // Step 4: Return the minimum element
    int getMin() {

        return minSt.top();
    }
};

int main() {

    // Create MinStack object
    MinStack st;

    // Push elements
    st.push(-2);
    st.push(0);
    st.push(-3);

    // Get minimum element
    cout << "Minimum: " << st.getMin() << endl;

    // Remove top element (-3)
    st.pop();

    // Get top element
    cout << "Top: " << st.top() << endl;

    // Get minimum element again
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}
