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
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {

        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current != nullptr)
        {

            // Store next node
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move prev one step ahead
            prev = current;

            // Move current one step ahead
            current = next;
        }

        // prev becomes the new head
        return prev;
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

    cout << "Original List: ";
    print(head);

    head = obj.reverseList(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}