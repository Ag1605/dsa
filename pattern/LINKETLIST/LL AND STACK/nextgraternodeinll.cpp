#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of ListNode
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        // Store linked list values into an array
        vector<int> nums;

        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        // Initialize answer array with 0
        // If no greater element exists, answer remains 0.
        vector<int> ans(nums.size(), 0);

        // Stack stores INDEXES, not values.
        stack<int> st;

        // Traverse array
        for (int i = 0; i < nums.size(); i++)
        {

            // Current element is greater than stack top element
            while (!st.empty() && nums[i] > nums[st.top()])
            {

                // Current number is next greater element
                ans[st.top()] = nums[i];

                // Remove that index
                st.pop();
            }

            // Push current index
            st.push(i);
        }

        return ans;
    }
};

// Insert node at end
void insert(ListNode *&head, int value)
{

    if (head == NULL)
    {
        head = new ListNode(value);
        return;
    }

    ListNode *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new ListNode(value);
}

// Print Linked List
void printList(ListNode *head)
{

    while (head)
    {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// Print Vector
void printVector(vector<int> &v)
{

    for (int x : v)
        cout << x << " ";

    cout << endl;
}

int main()
{

    ListNode *head = NULL;

    // Linked List = 2 -> 1 -> 5
    insert(head, 2);
    insert(head, 1);
    insert(head, 5);

    cout << "Linked List : ";
    printList(head);

    Solution obj;

    vector<int> ans = obj.nextLargerNodes(head);

    cout << "Answer      : ";
    printVector(ans);

    return 0;
}