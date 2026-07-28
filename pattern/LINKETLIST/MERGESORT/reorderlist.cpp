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
    // Function to reorder the linked list
    void reorderList(ListNode *head)
    {

        // If list has 0 or 1 node
        if (head == nullptr || head->next == nullptr)
            return;

        // ---------------- Step 1 : Find Middle ----------------

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        // ---------------- Step 2 : Reverse Second Half ----------------

        ListNode *prev = nullptr;
        ListNode *curr = slow->next;

        // Break the list into two halves
        slow->next = nullptr;

        while (curr != nullptr)
        {

            ListNode *next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        // ---------------- Step 3 : Merge Both Halves ----------------

        ListNode *first = head;
        ListNode *second = prev;

        while (second != nullptr)
        {

            ListNode *next1 = first->next;
            ListNode *next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};

// Insert node at end
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

    cout << "Original List : ";
    print(head);

    obj.reorderList(head);

    cout << "Reordered List : ";
    print(head);

    return 0;
}