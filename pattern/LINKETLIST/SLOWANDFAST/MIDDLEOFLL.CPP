#include <bits/stdc++.h>
using namespace std;

// Definition of ListNode
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to find the middle node
    ListNode *middleNode(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow by 1 step and fast by 2 steps
        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow will point to the middle node
        return slow;
    }
};

// Insert node at the end
void pushBack(ListNode *&head, int x)
{

    ListNode *newNode = new ListNode(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Print linked list
void print(ListNode *head)
{

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{

    Solution obj;

    int n;
    cin >> n;

    ListNode *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pushBack(head, x);
    }

    ListNode *middle = obj.middleNode(head);

    cout << "Middle Node = " << middle->val << endl;

    return 0;
}